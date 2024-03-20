///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a program that reads information about company employees (name, position, salary) 
/// from a text file and increases the salary of each employee by 10%, writing the updated 
/// information to a new file.
/// Write two functions: for txt and csv file.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>


void create(const std::string& filePath){
    std::ofstream file(filePath);

    std::string arr[3];

    for (int i = 0; i < 4; i++) {
        std::cin >> arr[0]
                 >> arr[1]
                 >> arr[2];
//                 >> arr[3]
//                 >> arr[4];

        file << arr[0] << ","
             << arr[1] << ","
             << arr[2]
//             << arr[3] << ","
//             << arr[4] << ","
             << "\n";
    }
}

void readTXT(const std::string& inputFilePath, const std::string& outputFilePath){
    std::ifstream input(inputFilePath);
    std::ofstream output(outputFilePath);
    std::string str, word;
    std::vector<std::vector<std::string>> txt_file;
    std::vector<std::string> words;
    output.setf(std::ios_base::fixed);

    while(std::getline(input, str)){
        words.clear();

        std::stringstream row(str);
        while (getline(row, word, ',')){
            words.push_back(word);
        }

        txt_file.push_back(words);
    }

    for (auto i : txt_file){
        for (int j = 0; j < 3; j++){
            if (j == 2) output << static_cast<int>(std::stod(i[j]) * 1.1) << '\n';
            else output << i[j] << ',';
        }
    }

    std::cout << "Txt file was read" << '\n';

    input.close();
    output.close();
}

void readCSV(const std::string& inputFilePath, const std::string& outputFilePath){
    std::ifstream input(inputFilePath);
    std::ofstream output(outputFilePath);
    std::string str, word;
    std::vector<std::vector<std::string>> csv_file;
    std::vector<std::string> words;
    output.setf(std::ios_base::fixed);

    while(std::getline(input, str)){
        words.clear();

        std::stringstream row(str);
        while (getline(row, word, ',')){
            words.push_back(word);
        }

        csv_file.push_back(words);
    }

    for (auto i : csv_file){
        for (int j = 0; j < 3; j++){
            if (j == 2) output << static_cast<int>(std::stod(i[j]) * 1.1) << '\n';
            else output << i[j] << ',';
        }
    }

    std::cout << "Csv file was read" << '\n';

    input.close();
    output.close();
}

void readFile(const std::string& inputFilePath, const std::string& outputFilePath){
    std::vector<std::string> words;
    std::stringstream row(inputFilePath);
    std::string word;

    while (getline(row, word, '.')) words.push_back(word);

    if (words[1] == "txt") readTXT(inputFilePath, outputFilePath);
    else readCSV(inputFilePath, outputFilePath);
}

int main() {
//    create("/Users/senya/CLionProjects/C-plus-plus-2024/week6/problem5_workers/input.csv");

    readFile( "/Users/senya/CLionProjects/C-plus-plus-2024/week6/problem5_workers/input.txt",
              "/Users/senya/CLionProjects/C-plus-plus-2024/week6/problem5_workers/output.txt");

    readFile( "/Users/senya/CLionProjects/C-plus-plus-2024/week6/problem5_workers/input.csv",
              "/Users/senya/CLionProjects/C-plus-plus-2024/week6/problem5_workers/output.csv");

    return 0;
}
