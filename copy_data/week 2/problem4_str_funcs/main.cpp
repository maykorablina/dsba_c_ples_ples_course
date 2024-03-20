////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 4: "Some functions for dealing with strings".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Try to use functions for dealing with strings:
/// 1) strcmp, strlen for c-strings;
/// 2) string:: size(), length(), operator<, operator+, operator= etc for
///    std::string-s.
///
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>


int main()
{
    char s1[256], s2[256];
    std::cin.getline(s1, 256);
    std::cin.getline(s2, 256);
    std::cout << std::strcmp(s1, s2) << ' ' << std::strlen(s1) << ' ' << std::strlen(s2) << '\n';

    std::string str1, str2;
    std::getline(std::cin, str1);
    std::getline(std::cin, str2);
    std::cout << str1.size() << ' ' << str1.length() << '\n'
            << str1.operator+=(str2) << '\n' << str1.operator=(str2);


    return 0;
}
