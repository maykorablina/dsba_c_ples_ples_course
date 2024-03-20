#include <iostream>

int main() {
    int n, k, m;
    std::cin >> n >> k >> m;

    if (k >= m) {
        int counter = 0, k_counter;
        while (n >= k){
            k_counter = n / k;
            n %= k;
            counter += (k / m) * k_counter;
            n += (k % m) * k_counter;
        }

        std::cout << counter;
    }
    else std::cout << 0;

    return 0;
}
