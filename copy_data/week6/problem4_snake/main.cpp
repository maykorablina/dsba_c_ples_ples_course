///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       22.01.2022
///
/// TASK DESCRIPTION
///
/// Read a single integer n from the file. In another file, write a matrix filled 
/// in the following way:
/// 1   2   3   4
/// 12  13  14  5
/// 11  16  15  6
/// 10  9   8   7
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <vector>


void createMatrix(const std::string& filePath, int size){
    std::ofstream file(filePath);

    std::vector<std::vector<int>> matrix;
    std::vector<int> row;
    for (int i = 0; i < size; i++) {
        matrix.push_back(row);
        for (int j = 0; j < size; j++) matrix[i].push_back(0);
    }

    int counter = 1, start = 0;
    for (int i = 0; i < size / 2 + 1; i++){
        //horizontal
        for (int j = start; j < size - start; j++) {
            matrix[i][j] = counter;
            std::cout << "i: " << i << "\tj: " << j << "\tcounter: " << counter << "\t\t";
            counter++;
        }
        std::cout << '\n';
        start++;

        //vertical
        for (int j = start; j < size + 1 - start; j++) {
            matrix[j][size - start] = counter;
            std::cout << "i: " << j << "\tj: " << size - start << "\tcounter: " << counter << "\t\t";
            counter++;
        }
        std::cout << '\n';

        //rev horizontal
        for (int j = size - 1 - start; j >= start - 1; j--) {
            matrix[size - 1 - i][j] = counter;
            std::cout << "i: " << size - 1 - i << " \tj: " << j << "\tcounter: " << counter << "\t\t";
            counter++;
        }
        std::cout << '\n';

        //rev vertical
        for (int j = size - 1 - start; j >= start; j--) {
            matrix[j][start - 1] = counter;
            std::cout << "i: " << j << "\tj: " << start - 1 << "\tcounter: " << counter << "\t\t";
            counter++;
        }
        std::cout << "\n\n";
    }

    for (auto num : matrix){
        for (int j = 0; j < size; j++){
            file << num[j] << '\t';
        }
        file << '\n';
    }

    file.close();
}

int main() {
    std::ifstream file("/Users/senya/CLionProjects/Plusi dla loxov/week6/problem4_snake/input.txt");
    std::string n;
    file >> n;
    file.close();

    createMatrix("/Users/senya/CLionProjects/Plusi dla loxov/week6/problem4_snake/file.txt",
                 std::stoi(n));
    return 0;
}