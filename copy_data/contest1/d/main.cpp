#include <iostream>

int main() {
    int n;
    std::cin >> n;

    float sum = 1;
    float power = -1;
    for (int i = 2; i < n + 1; i++){
        sum += power / i;
        power *= -1;
    }

    std::cout << sum;

    return 0;
}
