///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Develop a program to append content to the end of an existing file without overwriting its current content.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>


void appendToFile(const std::string& filePath, const std::string& content){
    FILE* file = std::fopen(filePath.c_str(), "a");
    std::fprintf(file, "%s", content.c_str());
    std::fclose(file);
}

int main() {
    appendToFile("/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem8_append/existing_file.txt",
                 "Appended content.\n");
    return 0;
}
