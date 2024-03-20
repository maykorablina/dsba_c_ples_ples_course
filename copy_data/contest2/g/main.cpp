#include <iostream>


std::string SubOne(std::string str, int i){
    if (str[i] - '0' > 0) {
        str[i] -= 1;
    }
    else if (i != 0){
        str[i] = '9';
        str = SubOne(str, i - 1);
    }

    return str;
}

bool dev2(std::string str){
    return (str[str.length() - 1] - '0') % 2 == 0;
}

bool dev3(std::string str){
    int sum = 0, len = str.length();
    for (int i = 0; i < len; i++) sum += (str[i] - '0');

    return sum % 3 == 0;
}

bool dev4(std::string str){
    int len = str.length();
    if (len >= 2)
        return ((str[len - 2] - '0') * 10 + (str[len - 1] - '0')) % 4 == 0;
    else
        return (str[len - 1] - '0') % 4 == 0;
}

bool dev5(std::string str){
    return (str[str.length() - 1] - '0') % 5 == 0;
}

bool dev6(std::string str){
    return dev2(str) && dev3(str);
}

bool dev7(std::string str){
    int len = str.length();
    int rem = 0;
    for (int i = 0; i < len; ++i) rem = (rem * 10 + (str[i] - '0')) % 7;

    return rem == 0;
}

bool dev8(std::string str){
    int len = str.length();
    if (len >= 3)
        return ((str[len - 3] - '0') * 100 + (str[len - 2] - '0') * 10 + (str[len - 1] - '0')) % 8 == 0;
    else if (len == 2)
        return ((str[len - 2] - '0') * 10 + (str[len - 1] - '0')) % 8 == 0;
    else
        return (str[len - 1] - '0') % 8 == 0;
}

bool dev9(std::string str){
    int sum = 0, len = str.length();
    for (int i = 0; i < len; i++) sum += str[i] - '0';

    return sum % 9 == 0;
}

int Remainder(int num, std::string str){
    int len = str.length() - 1;

    if (num == 1) return 0;

    if (num == 2) {
        if (dev2(str)) return 0;
        else return 1;
    }

    if (num == 3){
        for (int j = 0; j < 3; j++) {
            if (dev3(str)) return j;
            str = SubOne(str, len);
        }
    }

    if (num == 4){
        for (int j = 0; j < 4; j++){
            if (dev4(str)) return j;
            str = SubOne(str, len);
        }
    }

    if (num == 5){
        for (int j = 0; j < 5; j++){
            if (dev5(str)) return j;
            str = SubOne(str, len);
        }
    }

    if (num == 6){
        for (int j = 0; j < 6; j++){
            if (dev6(str)) return j;
            str = SubOne(str, len);
        }
    }

    if (num == 7){
        for (int j = 0; j < 7; j++){
            if (dev7(str)) return j;
            str = SubOne(str, len);
        }
    }

    if (num == 8){
        for (int j = 0; j < 8; j++){
            if (dev8(str)) return j;
            str = SubOne(str, len);
        }
    }

    if (num == 9){
        for (int j = 0; j < 9; j++){
            if (dev9(str)) return j;
            str = SubOne(str, len);
        }
    }

    return 0;
}

int main()
{
    std::string str;
    int dev;
    std::cin >> dev >> str;
    std::cout << Remainder(dev, str);
    return 0;
}