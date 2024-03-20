///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Sum digits
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that takes a number and
/// find sum of digits recursively.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>


int SumOfDigits(int n){
    if (n == 0) return 0;

    int sum = n % 10;
    sum += SumOfDigits(n / 10);

    return sum;
}

int main()
{
    int num;
    std::cin >> num;
    std::cout << SumOfDigits(num);

    return 0;
}
