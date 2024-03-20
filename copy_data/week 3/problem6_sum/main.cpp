///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Sum of Two Numbers
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads two integers from the standard input and calculates
/// their sum using pointers. Print the result.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;
    int *a = &n, *b = &m;
    std::cout << *a + *b;

    return 0;
}
