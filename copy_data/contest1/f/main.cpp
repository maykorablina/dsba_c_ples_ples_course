#include <iostream>


int main()
{
    int arr_size, **arr, m;
    std::cin >> arr_size >> m;
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
            arr[i][j] = (arr[0][j] * arr[i][0]) % m;
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