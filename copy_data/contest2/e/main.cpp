#include <iostream>


std::string AddOne(std::string str, int i){
    if (str[i] - '0' < 9) {
        str[i] += 1;
    }
    else if (i == 0){
        str[i] = '0';
        return "1" + str;
    }
    else{
        str[i] = '0';
        str = AddOne(str, i - 1);
    }

    return str;
}

int main() {
    std::string str;
    std::cin >> str;
    std::cout << AddOne(str, str.length() - 1);

    return 0;
}
