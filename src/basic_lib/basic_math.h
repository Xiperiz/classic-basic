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

#ifndef BASIC_MATH_H
#define BASIC_MATH_H

#include <math.h>

/*
    ABS when used on floating point number
*/
inline double basic_abs_f(double val)
{
    return fabs(val);
}

/*
    ABS when used on integer
*/
inline int basic_abs(int val)
{
    return abs(val);
}

/* 
    SIN with argument in radians
*/
inline double basic_sin(double rad)
{
    return sin(rad);
}

/* 
    COS with argument in radians
*/
inline double basic_cos(double rad)
{
    return cos(rad);
}

/* 
    TAN with argument in radians
*/
inline double basic_tan(double rad)
{
    return tan(rad);
}

/* 
    ATN with argument in radians
*/
inline double basic_arctan(double rad)
{
    return atan(rad);
}

/* 
    ASN with argument in radians
*/
inline double basic_arcsin(double rad)
{
    return asin(rad);
}

/* 
    ACS with argument in radians
*/
inline double basic_arccos(double rad)
{
    return acos(rad);
}

/*
    EXP
*/
inline double basic_exp(double power)
{
    return exp(power);
}

/*
    INT
*/
inline double basic_int(double val)
{
    return floor(val);
}

/*
    INTCEIL
*/
inline double basic_intcel(double val)
{
    return ceil(val);
}

/*
    RND
*/
inline double basic_rnd(double val)
{

}

/*
    SQR
*/
inline double basic_sqr(double val)
{
    return sqrt(val);
}

/*
    LOG
*/
inline double basic_log(double val)
{
    return log(val);
}

/*
    LOG10
*/
inline double basic_log10(double val)
{
    return log10(val);
}

/*
    FLT
*/
inline double basic_flt(double val)
{
    double discard;
    return modf(val, &discard);
}

#endif
