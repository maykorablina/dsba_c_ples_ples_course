///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Bit Manipulation - Count Set Bits
/// \version    0.1.0
/// \date       24.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program that reads an integer n from the standard input and determines
/// how many bits are set to 1 in its binary representation. Print the count of 
/// set bits.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{
    unsigned int n, count = 0;
    std::cin >> n;

    while (n){
        count += n & 1;
        n >>= 1;
    }

    std::cout << count;

    return 0;
}
