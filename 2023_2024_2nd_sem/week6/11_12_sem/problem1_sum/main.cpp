///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       14.02.2024
///
/// TASK DESCRIPTION
///
/// Write a function to read a file containing integers 
/// separated by spaces or newlines, sum these integers, 
/// and write the result to another file.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>

int sumIntegersInFile(const std::string& inputFilePath, const std::string& outputFilePath){
    std::string line;
    int number;
    int sum = 0;
    std::ifstream in(inputFilePath);
    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::istringstream iss(line);
            while (iss >> number) {
                sum += number;
            }
        }
    }
    in.close();

    std::ofstream out;
    out.open(outputFilePath);
    if (out.is_open())
    {
        out << sum << '\n';
    }
    out.close();
};

int main() {
    std::string input = "/Users/mayakorablina/Yandex.Disk.localized/CodingProjects/cpp_course_2_sem/2023_2024_2nd_sem/week6/11_12_sem/problem1_sum/input.txt";
    std::string output = "/Users/mayakorablina/Yandex.Disk.localized/CodingProjects/cpp_course_2_sem/2023_2024_2nd_sem/week6/11_12_sem/problem1_sum/output.txt";
    sumIntegersInFile(input, output);
    return 0;
}
