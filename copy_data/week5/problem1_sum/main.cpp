///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function to read a file containing integers 
/// separated by spaces or newlines, sum these integers, and write the result to another file.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>


void sumIntegersInFile(const std::string& inputFilePath, const std::string& outputFilePath){
    std::ifstream input(inputFilePath);
    std::ofstream output(outputFilePath);
    if (!input.is_open() or !output.is_open()) {
        std::cout << "Error blinb";
        return;
    }
    else std::cout << "Vse norm" << ' ';

    std::string str, num;
    int sum = 0;

    while (std::getline(input, str)){
        if (!str.empty()){
            num = "";

            for (char c : str){
                if (isdigit(c)) num += c;
                else if (!num.empty()){
                    sum += std::stoi(num);
                    num = "";
                }
            }
        }
    }

    output << sum;

    input.close();
    output.close();
}

int main() {
    sumIntegersInFile("/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem1_sum/input.txt",
                      "/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem1_sum/output.txt");

    std::cout << "Текущий рабочий каталог: " << std::filesystem::current_path() << std::endl;
    return 0;
}