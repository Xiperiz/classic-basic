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
#include "../helpers/compilers.h"
#include "interpreter.h"

struct interpreter_t * create_interpreter()
{
    struct interpreter_t *ret = (struct interpreter_t *)malloc(sizeof(struct interpreter_t));

    return ret;
}

void free_interpreter(struct interpreter_t *struct_ptr)
{
    free(struct_ptr);
}

bool run_interpreter(__maybe_unused struct interpreter_t * interpreter)
{
    // TODO
    return true;
}
