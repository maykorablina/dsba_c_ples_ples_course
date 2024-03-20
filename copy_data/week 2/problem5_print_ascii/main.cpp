////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 5: "Print ASCII table".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Print the “printable part” of the ASCII table using tabs for aligning.
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>


int main()
{
    char **arr;
    const int rows = 7, columns = 17;
    char arr_column[columns - 1] = {'0', '1', '2', '3', '4', '5', '6', '7', '8',
                                    '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char arr_rows[rows - 1] = {'2', '3', '4', '5', '6', '7'};
    arr = new char * [rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new char [columns];

    for (int i = 1; i < columns; i++) {
        arr[0][i] = arr_column[i - 1];
    }
    for (int i = 1; i < rows; i++) {
        arr[i][0] = arr_rows[i - 1];
    }

    int counter = 32, counter_end = 128;
    for (int i = 1; i < rows; i++){
        for (int j = 1; j < columns; j++){
            if (counter < counter_end) {
                arr[i][j] = static_cast<int>(counter);
                counter++;
            }
            else break;
        }
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++) {
            if (i == 0 && j == 0)
                std::cout << '\t';
            else
                std::cout << arr[i][j] << '\t';
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < rows; i++) delete[] arr[i];
    delete[] arr;
    return 0;
}