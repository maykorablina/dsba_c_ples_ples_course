///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Write a program to count the number of lines, words, and characters in a text file.
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>


void countFileStatistics(const std::string& filePath){
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cout << "Error blinb";
        return;
    }
    else std::cout << "Vse norm" << ' ';

    int count_characters = 0, count_words = 0, count_lines = 0, counter = 0;
    std::string str;

    while(std::getline(file, str)){
        count_lines++;
        if (!str.empty()) {
            for (char c : str) {
                if (isalpha(c)) counter++;
                else if (counter > 0) {
                    count_words++;
                    counter = 0;
                }

                if (c != ' ') count_characters++;
            }

            if (counter > 0) {
                count_words++;
                counter = 0;
            }
        }

    }

    std::cout << "Input file contains:" << '\n'
              << count_characters << " characters" << '\n'
              << count_words << " words" << '\n'
              << count_lines << " lines";

    file.close();
}

int main() {
    countFileStatistics("/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem3_statictics/file.txt");
    return 0;
}