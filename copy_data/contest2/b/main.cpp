#include <iostream>
#include <algorithm>


bool IsItPolindrom(std::string line){

    std::string str;

    int len = line.length();
    for (int i = 0; i < len; i++){
        if (line[i] != ' ') str += line[i];
    }

    std::string str_rev(str);
    std::reverse(str_rev.begin(), str_rev.end());

    if (str == str_rev) return true;
    return false;
}

int main() {
    std::string line, str;
    std::getline(std::cin, line);

    if (IsItPolindrom(line)) std::cout << "yes";
    else std::cout << "no";

    return 0;
}
