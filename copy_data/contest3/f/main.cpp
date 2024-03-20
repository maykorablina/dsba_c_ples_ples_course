#include <iostream>


std::string ExtractDigits(const std::string& s){
    std::string result = "";

    for (char c : s)
        if (isdigit(c)) result += c;

    return result;
}

int main()
{
    std::string str;
    std::getline(std::cin, str);

    std::cout << ExtractDigits(str);

    return 0;
}
