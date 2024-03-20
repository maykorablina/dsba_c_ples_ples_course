///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Print Data
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write overloaded functions `void print(int)` and `void print(double)` that
/// print an integer and a double, respectively.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#define defprint(A) std::cout << A << '\n'

void print(int f){
    std::cout << f << '\n';
}

void print(double f){
    std::cout << f << '\n';
}

int main()
{
    int num_1;
    double num_2;
    std::string str;
    std::cin >> num_1 >> num_2 >> str;
    print(num_1);
    print(num_2);
    defprint(num_1);
    defprint(num_2);
    defprint(str);

    return 0;
}

