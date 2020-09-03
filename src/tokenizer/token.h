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

#ifndef TOKEN_H
#define TOKEN_H

enum token_type_e
{
    TOKEN_UNKNOWN,
    TOKEN_IDENTIFIER,
    TOKEN_LITERAL_STRING,
    TOKEN_LITERAL_NUMBER,
    TOKEN_OPEN_PAREN,
    TOKEN_CLOSE_PAREN,
    TOKEN_OPEN_SQUARE_PAREN,
    TOKEN_CLOSE_SQUARE_PAREN,
    TOKEN_EQUAL,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_ASTERIKS,
    TOKEN_SLASH,
    TOKEN_EXPONENTAL,
    TOKEN_PERCENT,
    TOKEN_HASH,
    TOKEN_DOLLAR,
    TOKEN_EXCLAMATION,
    TOKEN_COMMA,
    TOKEN_DOT,
    TOKEN_APOSTROPHE,
    TOKEN_SEMI_COLON,
    TOKEN_COLON,
    TOKEN_AMPERSAND,
    TOKEN_QUESTION_MARK,
    TOKEN_LESS_THAN,
    TOKEN_MORE_THAN,
    TOKEN_BACKSLASH,
    TOKEN_AT,
    TOKEN_UNDERSCORE
};

struct position_t
{
    int x;
    int y;
};

struct token_t
{
    enum token_type_e type;
    char *literal;
    struct position_t pos;
};

#endif
