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

#ifndef NODE_H
#define NODE_H

#include <stdbool.h>
#include "../tokenizer/token.h"

enum node_type_e
{
    NODE_UNKNOWN,
    NODE_VAR_ASSIGN,
    NODE_LOOP,
};

struct basic_program_node_t
{
    enum node_type_e type;
    struct token_t *tokens;
    int token_count;
    char *literal_line;
    int basic_line;
    struct basic_program_node_t *previous;
    struct basic_program_node_t *next;
};

struct basic_program_node_t * create_program_node(enum node_type_e type, struct token_t *tokens, int token_count, char *literal_line, int basic_line);

void add_to_program_node_list(struct basic_program_node_t *any_node, struct basic_program_node_t *node_to_add);

void free_program_node(struct basic_program_node_t *node, bool relink);

void free_program_node_list(struct basic_program_node_t *any_node);

bool update_program_node_from_literal(struct basic_program_node_t *target_node);

#endif
