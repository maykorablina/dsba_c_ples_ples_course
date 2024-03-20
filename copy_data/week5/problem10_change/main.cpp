///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
///Write a program that reads a text file, converts all lowercase letters to uppercase, and writes the result to a new file.
///////////////////////////////////////////////////////////////////////////////

#include <fstream>
#include <iostream>
#include <cctype> // For toupper()
#include <vector>


void convertToLowercase(const std::string& inputFilePath, const std::string& outputFilePath){
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

    while (std::getline(input, str)) {
        if (!str.empty()) {
            for (auto & c : str) if (islower(c)) c = toupper(c);
            up_file.push_back(str);
        }
        else up_file.push_back("");
    }
    input.close();

    std::copy(up_file.begin(), up_file.end(),
              std::ostream_iterator<std::string>(output, "\n"));

    output.close();
}

int main() {
    convertToLowercase("/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem10_change/input.txt",
                       "/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem10_change/output_uppercase.txt");
    return 0;
}
