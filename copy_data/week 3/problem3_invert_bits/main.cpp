///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Bit Manipulation - Bitwise Complement
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that takes an integer n as input and performs bitwise complement
/// (inverts all bits) on it. Print the resulting number in binary and decimal forms.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
#include <bitset>


int main()
{
    unsigned int n, s;
    std::cin >> n;
    s = (int) std::log2(n) + 1;
    std::bitset<32> n_b_1(n);
    n = ((1 << s) - 1) ^ n;
    std::bitset<32> n_b_2(n);
    std::cout << n << '\n' << n_b_1 << '\n' << n_b_2;
    return 0;
}
