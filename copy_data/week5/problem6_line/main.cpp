///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Create a program to extract a specific line number from a text file and write it to another file.
///////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <vector>


void extractLineToFile(const std::string& inputFilePath, const std::string& outputFilePath, int lineNum){
    std::ifstream input(inputFilePath);
    std::ofstream output(outputFilePath);
    if (!input.is_open() or !output.is_open()) {
        std::cout << "Error blinb";
        return;
    }
    else std::cout << "Vse norm" << ' ';

    std::vector<std::string> up_file;
    std::string str;
    int counter = 0;

    while(std::getline(input, str)) {
        if (counter == lineNum) output << str << '\n';
        else up_file.push_back(str);
        counter++;
    }
    input.close();
    output.close();

    std::ofstream update_input(inputFilePath);
    if (!update_input.is_open()) {
        std::cout << "Error blinb";
        return;
    }
    else std::cout << "Vse norm" << ' ';

    std::copy(up_file.begin(), up_file.end(),
              std::ostream_iterator<std::string>(update_input, "\n"));

    update_input.close();
}
int main() {
    extractLineToFile("/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem6_line/input.txt",
                      "/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem6_line/specific_line.txt", 1);
    return 0;
}

