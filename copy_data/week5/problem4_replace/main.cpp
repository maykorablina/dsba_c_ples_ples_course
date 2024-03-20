///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function to find and replace all occurrences of a word in a file.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <vector>


std::string join(const std::vector<std::string>& tokens, char delimiter) {
    std::string result = "";
    int size = tokens.size();

    for (int i = 0; i < size; i++){
        if (i != size - 1) result += (tokens[i] + delimiter);
        else result += tokens[i];
    }

    return result;
}

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

void findAndReplaceInFile(const std::string& filePath, const std::string& toFind, const std::string& toReplace){
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cout << "Error blinb";
        return;
    }
    else std::cout << "Vse norm" << ' ';

    std::vector<std::string> up_file, words;
    std::string str;
    int counter = 0;

    while(std::getline(file, str)) {
        words = split(str, ' ');

        for (auto & word : words)
            if (word == toFind) word = toReplace;

        str = join(words, ' ');
        up_file.push_back(str);
    }
    file.close();

    std::ofstream new_file(filePath);
    if (!new_file.is_open()) {
        std::cout << "Error blinb";
        return;
    }
    else std::cout << "Vse norm" << ' ';

    std::copy(up_file.begin(), up_file.end(),
              std::ostream_iterator<std::string>(new_file, "\n"));

    new_file.close();
}

int main() {
    findAndReplaceInFile("/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem4_replace/file.txt",
                         "oldWord", "newWord");
    return 0;
}