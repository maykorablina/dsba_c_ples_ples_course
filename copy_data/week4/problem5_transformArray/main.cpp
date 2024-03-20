///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Array Transformation
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `void transformArray(int* arr, int size, int (*transform)(int))`
/// that applies a transformation function to each element of an array.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>


int trans(int n){
    return n * 2;
}

void transformArray(int* arr, int size, int (*transform)(int)){
    for (int i = 0; i < size; i++){
        arr[i] = transform(arr[i]);
    }
}

int main()
{
    int size;
    std::cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++) std::cin >> arr[i];

    transformArray(arr, size, trans);

    for (int i = 0; i < size; i++) std::cout << arr[i] << ' ';

    return 0;
}
