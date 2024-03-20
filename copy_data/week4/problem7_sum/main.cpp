///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Sum of Numbers
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a variadic function `int sum(int count, ...)` that returns the sum of 
/// 'count' numbers.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdarg>


int sum(int count, ...){
    int res = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) res += va_arg(args, int);
    return res;
}


int main()
{
    auto res = sum(2, 2, 3, 4, 5, 6);
    std::cout << res;

    return 0;
}

