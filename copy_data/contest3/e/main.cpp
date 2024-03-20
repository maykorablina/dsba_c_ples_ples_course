#include <iostream>


std::vector<std::string> split(const std::string& str, char delimiter){
    std::vector<std::string> result = {""};
    int counter = 0, len = str.length();

    for (int i = 0; i < len; i++){
        if (str[i] != delimiter) result[counter] += str[i];
        else{
            result.push_back("");
            counter++;
        }
    }

    return result;
}

int main(){
    std::vector<std::string> arr(split("13-24--08-11-2014", '-'));

    for (auto & i : arr) std::cout << i << ' ';

    return 0;
}