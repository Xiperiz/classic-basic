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
#include "interpreter/interpreter.h"
#include "interpreter/node.h"
#include "helpers/print_info.h"
#include "tokenizer/file_io.h"

int main(int argc, char **argv)
{
    argc--;
    argv++;

    if (argc == 0)
    {
        print_usage();
        return -1;
    }

    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-v") == 0)
        {
            print_version();
            return 0;
        }
    }

    struct source_file_t *file_struct = file_to_struct(*argv);

    if (file_struct->err)
    {
        free(file_struct);
        return -1;
    }

    struct basic_program_node_t *program_start_node = create_program_node(NODE_UNKNOWN, NULL, 0, file_struct->lines[0], 0);
    if (!update_program_node_from_literal(program_start_node))
    {
        free_source_file_t(file_struct);
        free_program_node_list(program_start_node);
        return -1;
    }

    if (file_struct->line_count > 1)
    {
        for (int i = 1; i < file_struct->line_count; i++)
        {
            struct basic_program_node_t *node = create_program_node(NODE_UNKNOWN, NULL, 0, file_struct->lines[i], 0);
            if (!update_program_node_from_literal(node))
            {
                free_source_file_t(file_struct);
                free_program_node_list(program_start_node);
                return -1;
            }

            add_to_program_node_list(program_start_node, node);
        }
    }

    if (!reorder_nodes(program_start_node))
        return -1;

    /* Debug */
    struct basic_program_node_t *temp_ptr = program_start_node;
    while (temp_ptr->next != NULL)
    {
        printf("%s\n", temp_ptr->literal_line);
        temp_ptr = temp_ptr->next;
    }

    struct interpreter_t *interpreter = create_interpreter(); // TODO Cmd args etc

    int to_ret = 0;
    if (!run_interpreter(interpreter))
        to_ret = -1;

    free_interpreter(interpreter);
    free_source_file_t(file_struct);
    free_program_node_list(program_start_node);

    return to_ret;
}
