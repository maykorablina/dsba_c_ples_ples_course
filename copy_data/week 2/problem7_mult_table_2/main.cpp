////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 7: "Multiplication Table".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Program asks a user for two numbers, 1 <= (m, n) <= 8 and prints a rectangle
/// multiplication table aligning output at tab positions.
///
////////////////////////////////////////////////////////////////////////////////
#include <iostream>


int main()
{
    int arr_size, m, n, min, current;
    int **arr;
    std::cin >> m >> n;
    min = m > n ? n : m;
    arr_size = std::abs(m - n) + 2;
    arr = new int * [arr_size];
    for (int i = 0; i < arr_size; i++)
        arr[i] = new int [arr_size];

    arr[0][0] = 0;
    current = min;
    for (int i = 1; i < arr_size; i++) {
        arr[0][i] = current;
        current++;
    }
    current = min;
    for (int i = 1; i < arr_size; i++) {
        arr[i][0] = current;
        current++;
    }

    for (int i = 1; i < arr_size; i++){
        for (int j = 1; j < arr_size; j++){
            arr[i][j] = arr[0][j] * arr[i][0];
        }
    }

    for (int i = 0; i < arr_size; i++){
        for (int j = 0; j < arr_size; j++)
            if (i == 0 && j == 0)
                std::cout << '\t';
            else
                std::cout << arr[i][j] << '\t';
        std::cout << std::endl;
    }

    delete[] arr;
    return 0;
}