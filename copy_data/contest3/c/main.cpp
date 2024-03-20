#include "iostream"



std::string common_suffix(const std::string& a, const std::string& b){
    std::string result = "";
    int len_a = a.length(), len_b = b.length();
    int len_min = len_a > len_b ? len_b : len_a;
    if (len_min == 0) return "";
    len_a--, len_b--;

    for (int i = 0; i < len_min; i++){
        if (a[len_a - i] == b[len_b - i]) result += a[len_a - i];
        else break;
    }

    std::string rev_result = "";
    for (int i = result.length() - 1; i >= 0; i--) rev_result += result[i];

    return rev_result;
}

int main(){
    std::cout << common_suffix("apple", "tuple");


    return 0;
}