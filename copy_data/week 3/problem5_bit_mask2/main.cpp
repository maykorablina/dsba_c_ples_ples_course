///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Bit Manipulation - Set Bit
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that takes an integer n and a position k as input. The program
/// should set (change to 1) the k-th bit of the integer n and print the resulting
/// number in binary and decimal forms.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <bitset>

int main()
{
    unsigned int n, k, res;
    std::cin >> n >> k;
    std::bitset<32> n_b(n);
    std::cout << n_b << '\n';
    n_b[k] = true;
    std::cout << n_b << '\n';
    res = (int)(n_b.to_ulong());
    std::cout << res;

    return 0;
}
