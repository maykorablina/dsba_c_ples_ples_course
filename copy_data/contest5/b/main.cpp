#include <iostream>
#include <vector>
#include <map>


int SumOfVector(std::vector<int> u, std::vector<int> v, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) sum += u[i] * v[i];

    return sum;
}


int main()
{
    int m, n, num;
    std::vector<int> vec;
    std::string key;
    std::vector<std::pair<std::string, std::vector<int>>> arr;
    std::cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        vec.clear();
        std::cin >> key;

        for (int j = 0; j < n; j++)
        {
            std::cin >> num;
            vec.push_back(num);
        }

        arr.push_back({key, vec});
    }

    int maximum = 0;
    std::vector<std::string> max_output;
    bool flag = true;

    for (auto el: arr)
    {
        if (el.first != arr[0].first && flag)
        {
            maximum = SumOfVector(arr[0].second, el.second, n);
            max_output = {el.first};
            flag = false;
        }
        else if (el.first != arr[0].first)
        {
            if (maximum < SumOfVector(arr[0].second, el.second, n))
            {
                maximum = SumOfVector(arr[0].second, el.second, n);
                max_output = {el.first};
            }
            else if (maximum == SumOfVector(arr[0].second, el.second, n))
            {
                max_output.push_back(el.first);
            }
        }
    }

    for (auto el: max_output) std::cout << el << '\n';

    return 0;
}