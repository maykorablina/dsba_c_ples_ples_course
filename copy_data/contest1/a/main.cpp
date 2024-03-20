#include <iostream>
#include <cmath>


int main()
{
    int arr[4];
    for (int i = 0; i < 4; i++){
        std::cin >> arr[i];
    }

    if (arr[0] == arr[2] || arr[1] == arr[3]){
        std::cout << "YES";
    }
    else if (abs(arr[0] - arr[2]) == abs(arr[1] - arr[3])){
        std::cout << "YES";
    }
    else std::cout << "NO";

    return 0;
}
