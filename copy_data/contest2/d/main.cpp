#include <iostream>


std::string Clear(std::string str){
    std::string res = "";
    std::string r_1 = "bfpv", r_2 = "cgjkqsxz", r_3 = "dt", r_4 = "l", r_5 = "mn", r_6 = "r", r_7 = "aehiouwy";

    while(str.length() > 0){
        if(r_1.find(str[0]) != std::string::npos){
            res += '1';
            str.erase(0, 1);
        }
        else if(r_2.find(str[0]) != std::string::npos){
            res += '2';
            str.erase(0, 1);
        }
        else if(r_3.find(str[0]) != std::string::npos){
            res += '3';
            str.erase(0, 1);
        }
        else if(r_4.find(str[0]) != std::string::npos){
            res += '4';
            str.erase(0, 1);
        }
        else if(r_5.find(str[0]) != std::string::npos){
            res += '5';
            str.erase(0, 1);
        }
        else if(r_6.find(str[0]) != std::string::npos){
            res += '6';
            str.erase(0, 1);
        }
        else str.erase(0, 1);
    }

    return res;
}

std::string Soundex(std::string str){
    std::string res = "";
    res += str[0];
    str.erase(0, 1);

    res += Clear(str);

    int len = res.length(), i = 1;
    while (i < res.length() - 1){
        if (res[i] == res[i + 1]) res.erase(i + 1, 1);
        else i++;
    }

    if (res.length() > 4)
        res.erase(4, res.length() - 4);
    else{
        res += "000";
        res.erase(4, res.length() - 4);
    }

    return res;
}

int main() {
    std::string str;
    std::cin >> str;
    std::cout << Soundex(str);

    return 0;
}
