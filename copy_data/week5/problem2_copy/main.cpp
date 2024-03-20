///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Create a function that copies the content of one file to another file.
///
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream> 

void copyFile(const std::string& sourceFilePath, const std::string& destinationFilePath){
    std::ifstream input(sourceFilePath);
    std::ofstream output(destinationFilePath);
    if (!input.is_open() or !output.is_open()) {
        std::cout << "Error blinb";
        return;
    }
    else std::cout << "Vse norm" << ' ';

    std::string str;

    while (std::getline(input, str)){
        output << str << '\n';
    }

    input.close();
    output.close();
}

int main() {
    copyFile("/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem2_copy/sourсe.txt",
             "/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem2_copy/destination.txt");
    return 0;
}
