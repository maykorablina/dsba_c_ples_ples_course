///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Filter Array
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `int* filter(int* arr, int size, int& newSize, bool (*filterFunc)(int))`
/// that filters an array based on a predicate function and returns a new array.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>


bool filter_arr(int element){
    if (element > 8) return true;
    return false;
}

std::vector<int> filter(std::vector<int> arr, int& newSize, bool (*filterFunc)(int)){
    std::vector<int> new_arr;

    for (int i = 0; i < arr.size(); i++){
        if (filter_arr(arr[i]) and new_arr.size() < newSize) {
            new_arr.push_back(arr[i]);
        }
        else if (new_arr.size() >= newSize) break;
    }

    return new_arr;
}

int main()
{
    std::vector<int> arr, new_arr;
    int n, num, new_size = 5;
    std::cin >> n;

    for (int i = 0; i < n; i++){
        std::cin >> num;
        arr.push_back(num);
    }

    new_arr = filter(arr, new_size, filter_arr);

    for (int el : new_arr) std::cout << el << '\t';

    return 0;
}
