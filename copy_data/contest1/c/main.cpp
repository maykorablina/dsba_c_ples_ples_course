#include <iostream>

int main() {
    int v, t;
    std::cin >> v >> t;

    int distance = v * t;
    int result = distance % 109;
    result = result >= 0 ? result : 109 + result;

    std::cout << result;

    return 0;
}
