///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program to read the content of a text file and write its content in reverse order to another file.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <vector>

void reverseFileContent(const std::string& inputFilePath, const std::string& outputFilePath){
    std::ifstream input(inputFilePath);
    std::ofstream output(outputFilePath);
    if (!input.is_open() or !output.is_open()) {
        std::cout << "Error blinb";
        return;
    }
    else std::cout << "Vse norm" << ' ';

    std::string str;
    std::vector<std::string> arr;

    while(std::getline(input, str)){
        std::reverse(str.begin(), str.end());
        arr.emplace(arr.cbegin(), str);
    }

    for (auto i : arr) output << i << '\n';

    input.close();
    output.close();
}

int main() {
    reverseFileContent("/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem5_reverse/input.txt",
                       "/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem5_reverse/reversed_input.txt");
    return 0;
}
