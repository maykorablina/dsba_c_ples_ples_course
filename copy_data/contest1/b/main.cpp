#include <iostream>

int main() {
    std::string nums;
    std::cin >> nums;

    unsigned int sum = 0;
    int length = nums.length();
    for (int i = 0; i < length; i++){
        sum += nums[i] - '0';
    }

    std::cout << sum;

    return 0;
}
