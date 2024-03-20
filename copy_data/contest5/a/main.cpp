#include <iostream>
#include <vector>
#include <set>


int main()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    std::multiset<int> sorted_arr;

    for (int i = 0; i < n; i++) std::cin >> arr[i];

    for (int i = 0; i < k; i++) sorted_arr.insert(arr[i]);

    for (int i = k - 1; i < n; i++)
    {
        std::cout << *sorted_arr.begin() << "\n";
        sorted_arr.erase(sorted_arr.find(arr[i - k + 1]));
        sorted_arr.insert(arr[i + 1]);
    }

    return 0;
}