//
// Created by Майя Кораблина on 08/02/24.
//
#include <iostream>
#include <set>
#include <vector>

int main()
{
    int k, okno;
    std::cin >> k >> okno;
    std::multiset<int> a;
    std::vector<int> vec(k);
    for (int i = 0; i < k; i++)
    {
        std::cin >> vec[i];
    }
    a.insert(vec.begin(), vec.begin() + okno);
    for (int i = okno; i <= k; i++)
    {
        std::cout << *a.begin() << '\n';
        a.erase(a.find(vec[i - okno]));
        a.insert(vec[i]);
    }

    return 0;
}
