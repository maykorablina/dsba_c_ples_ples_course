///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Swap Variables
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads two integers from the standard input and swaps
/// their values using pointers. Print the swapped values.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;
    int *a = &n, *b = &m;
    int *c = a;
    a = b;
    b = c;

    std::cout << *a << ' ' << *b;


    return 0;
}
