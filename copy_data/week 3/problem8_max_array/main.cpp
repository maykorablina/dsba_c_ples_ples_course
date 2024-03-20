///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: Pointers - Find Maximum Element
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program that reads an array of integers from the standard input and
/// finds the maximum element using pointers. Print the maximum element.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

int max_num(int *arr, int size){
    int maximum = arr[0];
    for (int i = 1; i < size; i++) if (maximum < arr[i]) maximum = arr[i];

    return maximum;
}

int main()
{
    int size;
    std::cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) std::cin >> arr[i];

    std::cout << max_num(arr, size);

    return 0;
}
