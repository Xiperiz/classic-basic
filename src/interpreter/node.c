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
#include "../tokenizer/tokenizer.h"
#include "../helpers/compilers.h"
#include "node.h"

struct basic_program_node_t * create_program_node(enum node_type_e type, struct token_t *tokens, int token_count, char *literal_line, int basic_line)
{
    struct basic_program_node_t *ret = (struct basic_program_node_t *)malloc(sizeof(struct basic_program_node_t));

    ret->type = type;
    ret->tokens = tokens;
    ret->token_count = token_count;
    ret->literal_line = literal_line;
    ret->basic_line = basic_line;

    return ret;
}

void add_to_program_node_list(struct basic_program_node_t *any_node, struct basic_program_node_t *node_to_add)
{
    struct basic_program_node_t *temp_ptr = any_node;

    // Find last node to link to
    while (temp_ptr->next != NULL)
        temp_ptr = temp_ptr->next;

    temp_ptr->next = node_to_add;
    node_to_add->previous = temp_ptr;
}

void free_program_node(struct basic_program_node_t *node, bool relink)
{
    if (relink)
    {
        struct basic_program_node_t *next_ptr = node->next;
        struct basic_program_node_t *previous_ptr = node->previous;

        if (previous_ptr != NULL)
            previous_ptr->next = next_ptr;

        if (next_ptr != NULL)
            next_ptr->previous = previous_ptr;
    }

    free(node->tokens);
    free(node);
}


void free_program_node_list(struct basic_program_node_t *any_node)
{
    struct basic_program_node_t *next_iterator = any_node->next;
    struct basic_program_node_t *previous_iterator = any_node->previous;

    while (next_iterator != NULL)
    {
        struct basic_program_node_t *next_ptr = next_iterator->next;
        free_program_node(next_iterator, false);
        next_iterator = next_ptr;
    }

    while (previous_iterator != NULL)
    {
        struct basic_program_node_t *previous_ptr = previous_iterator->previous;
        free_program_node(previous_iterator, false);
        previous_iterator = previous_ptr;
    }

    free_program_node(any_node, false);
}

bool update_program_node_from_literal(struct basic_program_node_t *target_node)
{
    struct tokenized_string_t tokenizer_output = tokenize_string(target_node->literal_line);
    if (tokenizer_output.err)
        return false;

    target_node->basic_line = tokenizer_output.basic_line;
    target_node->tokens = tokenizer_output.tokens;
    target_node->token_count = tokenizer_output.token_count;

    return true;
}

/*
static void add_node_to_the_front(struct basic_program_node_t *any_node, struct basic_program_node_t *node_to_prepend)
{
    struct basic_program_node_t *temp_ptr = any_node;

    // Move to the front
    while (temp_ptr->previous != NULL)
        temp_ptr = temp_ptr->previous;

    // Temp ptr is now first element in linked list
    node_to_prepend->next = temp_ptr;
    node_to_prepend->previous = NULL;
}

static void add_node_to_the_end(struct basic_program_node_t *any_node, struct basic_program_node_t *node_to_prepend)
{
    struct basic_program_node_t *temp_ptr = any_node;

    // Move to the front
    while (temp_ptr->next != NULL)
        temp_ptr = temp_ptr->next;

    // Temp ptr is now last element in linked list
    node_to_prepend->next = NULL;
    node_to_prepend->previous = temp_ptr;
}
*/

bool reorder_nodes(__maybe_unused struct basic_program_node_t *any_node)
{
    // TODO
    return true;
}
