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

#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdbool.h>
#include "token.h"

struct tokenized_string_t
{
    struct token_t *tokens;
    int token_count;
    int basic_line;
    bool err;
};

struct tokenized_string_t tokenize_string(char *str);

#endif
