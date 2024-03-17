#include <iostream>
#include <vector>
#include <algorithm>

int scalar(std::vector<int> v1, std::vector<int> v2, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += v1[i] * v2[i];
    }
    return sum;
}

int main()
{
    int words, lens;
    std::cin >> words >> lens;
    std::vector<std::string> word_list;
    std::vector<std::vector<int>> data;
    for (int i = 0; i < words; i++)
    {
        std::vector<int> a;
        std::string name;
        std::cin >> name;
        word_list.push_back(name);
        for (int j = 0; j < lens; j++)
        {
            int n;
            std::cin >> n;
            a.push_back(n);
        }
        data.push_back(a);
        a.clear();
    }
    std::vector<int> new_data;
    std::vector<int> data_to_compare = data[0];
    for (int i = 0; i < words; i++)
    {
        int sc = scalar(data_to_compare, data[i], lens);
        new_data.push_back(sc);
    }
    std::vector<int> max_indices;
    int max_value = *std::max_element(new_data.begin(), new_data.end());
    for (int i = 0; i < words; i++)
    {
        if (new_data[i] == max_value)
        {
            max_indices.push_back(i);
        }
    }
    for (int i: max_indices)
    {
        if (i != 0)
        {
            std::cout << word_list[i] << '\n';
        }
    }
    return 0;
}
