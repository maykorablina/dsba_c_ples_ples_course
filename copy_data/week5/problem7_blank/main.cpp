///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program that removes all blank lines from a text file and writes the result to a new file.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <vector>


void RemoveBlanks(std::string name){
    std::ifstream file(name);
    if (!file.is_open()) {
        std::cout << "Error blinb";
        return;
    }
    else std::cout << "Vse norm" << ' ';

    std::string str;
    std::vector<std::string> arr;

    while(std::getline(file, str)){
        if (!str.empty()) arr.push_back(str);
    }
    file.close();

    std::ofstream up_file(name);
    std::copy(arr.begin(), arr.end(),
              std::ostream_iterator<std::string>(up_file, "\n"));

    up_file.close();
}


int main()
{
    RemoveBlanks("/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem7_blank/file.txt");

    return 0;
}
