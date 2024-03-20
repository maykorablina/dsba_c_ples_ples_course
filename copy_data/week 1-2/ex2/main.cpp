/*******************************************************************************
 *  Workshop 2/Task 2
 *
 *  Studying input, output, conditions and simple loops.
 *
 *  A program outputs a formatted multiplication table for n numbers.
 *
 *  Example. For n = 3, the output is:
 *
 *      1   2   3
 *  1   1   2   3
 *  2   2   4   6
 *  3   3   6   9
 *
 *  1) Ask a user to input a boundary n for the table.
 *  2) Check whether n is in the range [1; 10] using if statement. Otherwise
 *     output the following message: "Wrong argument", and terminate the program.
 *  3) Output a table row by row using for-loop statement. Use tabs to separate
 *     individual values.
 *  4) Modify the program. Use while-loop statement.
 *
 ******************************************************************************/

#include <iostream>

// the entrypoint of the application
int main()
{
    int arr_size;
    int **arr;
    std::cin >> arr_size;
    arr_size++;
    arr = new int * [arr_size];
    for (int i = 0; i < arr_size; i++)
        arr[i] = new int [arr_size];

    for (int i = 0; i < arr_size; i++) {
        arr[0][i] = i;
    }
    for (int i = 0; i < arr_size; i++) {
        arr[i][0] = i;
    }

    for (int i = 1; i < arr_size; i++){
        for (int j = 1; j < arr_size; j++){
            arr[i][j] = arr[0][j] * arr[i][0];
        }
    }

    for (int i = 0; i < arr_size; i++){
        for (int j = 0; j < arr_size; j++)
            if (arr[i][j] == 0)
                std::cout << "  ";
            else
                std::cout << arr[i][j] << ' ';
        std::cout << std::endl;
    }

    delete[] arr;
    return 0;
}

