 /*
    Classic Basic Interpreter
    Copyright (C) 2020  Xiperiz

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "../helpers/compilers.h"
#include "file_io.h"

static void string_into_line_array(char *buffer, struct source_file_t *struct_ptr)
{
    char *iterator = buffer;
    struct_ptr->lines = (char **)malloc(10000 * sizeof(char *)); // 10000 is a safe limit for lines of code TODO Make it a 'vector'
    struct_ptr->line_count = 0;

    while (true)
    {
        struct_ptr->lines[struct_ptr->line_count] = (char *)malloc(4096); // 4096 chars is a safe limit for a line of code TODO Make it a 'vector'
        int line_pos = 0;

        while (*iterator != '\0' && *iterator != '\n')
        {
            struct_ptr->lines[struct_ptr->line_count][line_pos] = *iterator;
            line_pos++;
            iterator++;
        }

        struct_ptr->lines[struct_ptr->line_count][line_pos] = '\0';

        if (*struct_ptr->lines[struct_ptr->line_count] != '\0')
            struct_ptr->line_count++;

        if (*iterator == '\0')
            break;
        else
            iterator++;
    }
}

struct source_file_t * file_to_struct(char *path)
{
    FILE *src_file = fopen(path, "rb");
    uint64_t f_len = 0;
    char *buffer = NULL;

    struct source_file_t* ret = (struct source_file_t *)malloc(sizeof(struct source_file_t));

    if (src_file)
    {
        fseek(src_file, 0, SEEK_END);
        f_len = ftell(src_file);
        fseek(src_file, 0, SEEK_SET);

        buffer = (char *)malloc(f_len + 1);

        if (buffer)
            fread(buffer, 1, f_len, src_file);
        else
        {
            printf("Can't read file or buffer allocation failed: %s\n", path);
            ret->err = true;
            ret->lines = NULL;

            return ret;
        }

        buffer[f_len] = '\0';

        fclose(src_file);
    }
    else
    {
        printf("Invalid file path provided: %s\n", path);
        ret->err = true;
        ret->lines = NULL;

        return ret;
    }

    string_into_line_array(buffer, ret);
    ret->err = false;

    free(buffer);
    return ret;
}

void free_source_file_t(struct source_file_t *target)
{
    /*for (int i = 0; i < target->line_count; i++)
        free(target->lines[i]);*/

    for (int i = 0; i < 10000; i++) // TODO Use upper snipet when lines is vector
        free(target->lines[i]); 

    free(target->lines);
    free(target);
}
