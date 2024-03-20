////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 1: "Hello, %username%".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Program asks a user for their name and then outputs "Hello, <user>",
/// where <user> is the name the user.
///
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 1: "Hello, %username%".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Program asks a user for their name and then outputs "Hello, <user>",
/// where <user> is the name the user.
///
////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>

void print_array(std::vector<int> v, char sep){
    for (int i = 0; i < v.size(); i++){
        if (i == v.size() - 1) std::cout << v[i];
        else std::cout << v[i] << sep;
    }
    std::cout << '\n';
}

std::vector<int> input_array(int size){
    std::vector<int> ans;
    int n;
    for (int i = 0; i < size; i++) {
        std::cin >> n;
        ans.push_back(n);
    }
    return ans;
}


int main()
{
    std::vector<int> a = input_array(6);
    print_array(a, ' ');
}

