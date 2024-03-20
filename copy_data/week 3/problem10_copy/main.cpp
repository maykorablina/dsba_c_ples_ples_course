///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Copy Array
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads an array of integers from the standard input,
/// creates a new array, copies the elements from the original array to the new
/// array using pointers, and then prints the new array.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int main()
{
    int size;
    std::cin >> size;

    int arr[size], new_arr[size], *ptr[size];

    for (int i = 0; i < size; i++){
        std::cin >> arr[i];
        ptr[i] = &arr[i];
    }

    for (int i = 0; i < size; i++) new_arr[i] = (*ptr[i]);

    for (auto el : new_arr) std::cout << el << ' ';

    return 0;
}
