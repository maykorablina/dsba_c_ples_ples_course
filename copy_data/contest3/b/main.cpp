#include <iostream>

int main()
{
    int size, index;
    std::cin >> size;
    int rev_arr[size];

    for (int i = 1; i < size + 1; i++){
        std::cin >> index;
        rev_arr[index - 1] = i;
    }

    for (int i : rev_arr) std::cout << i << ' ';

    return 0;
}