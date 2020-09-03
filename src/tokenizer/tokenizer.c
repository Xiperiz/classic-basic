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

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "tokenizer.h"

static int get_basic_line_number(char *str, char **no_line_string)
{
    int basic_line = (int)strtol(str, no_line_string, 10);

    if (basic_line == 0 && *str != '0')
    {
        printf("Every line of code needs line number.\n");
        return -1;
    }
    else
    {
        if (basic_line >= 65529)
        {
            printf("Line number out of range (0 -> 65529)\n");
            return -1;
        }
        else
            return basic_line;
    }
}

struct tokenized_string_t tokenize_string(char *str)
{
    struct tokenized_string_t ret;
    ret.tokens = NULL;
    ret.token_count = 0;

    char *no_line_str = NULL;

    ret.basic_line = get_basic_line_number(str, &no_line_str);
    if (ret.basic_line == -1)
    {
        ret.err = true;
        return ret;
    }

    struct token_t tokens_buffer[4096]; // TODO Change to vector
    int token_index = 0;

    char *iterator = no_line_str;

    /* Move to first non whitespace character */
    while (isspace(*iterator) != 0)
        iterator++;

    while (*iterator != '\0')
    {
        if (isspace(*iterator) != 0)
        {
            // TODO
        }

        // TODO
    }

    ret.err = false;
    return ret;
}
