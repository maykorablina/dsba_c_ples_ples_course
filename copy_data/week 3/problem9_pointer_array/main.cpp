///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Count Elements
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads an array of integers from the standard input and
/// counts the number of elements in the array using pointers. Print the count.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>


int main()
{
    std::vector<int> arr;
    int counter = 0;
    int *ptr = &counter;
    std::string str, num;
    std::getline(std::cin, str);

    while (!str.empty()) {
        for (char c : str) {
            if (isdigit(c)) num += c;
            else if (!num.empty()){
                arr.push_back(std::stoi(num));
                (*ptr)++;
                num = "";
            }
        }

        if (!num.empty()){
            arr.push_back(std::stoi(num));
            (*ptr)++;
            num = "";
        }

        std::getline(std::cin, str);
    }

    std::cout << counter;

    return 0;
}
