#include <iostream>


std::string join(const std::vector<std::string>& tokens, char delimiter) {
    std::string result = "";
    int size = tokens.size();

    for (int i = 0; i < size; i++){
        if (i != size - 1) result += (tokens[i] + delimiter);
        else result += tokens[i];
    }

    return result;
}

int main(){
    const std::vector<std::string> arr = {"What", "is", "my", "name?"};
    std::cout << join(arr, '_');

    return 0;
}