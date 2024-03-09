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
/// 8   7   6   5
/// 9   10  11  12
/// 16  15  14  13
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>


bool is_prime(int n) {
    int i, flag = 1;

    for (i = 2; i <= sqrt(n); i++) {

        if (n % i == 0) {
            flag = 0;
            break;
        }
    }

    if (n <= 1)
        flag = 0;
    if (flag) return true;
    else return false;
}


int read_number(std::string file_path) {
    std::fstream file(file_path, std::ios_base::in);
    int a;
    file >> a;
    return a;

}

std::vector<std::vector<int>> create_matrix(int n) {
    std::vector<std::vector<int>> ans;
    int rows;
    int cols;
    if (is_prime(n)) {
        cols = 1;
        rows = n;
    }
    else {
        std::vector<std::pair<int, int>> pairs;
        int temp = n / 2;

        for (int i = temp - 1; i > 0; i--) {
            if (n % i == 0) {
                cols = i;
                rows = n / i;
                pairs.push_back({rows, cols});
            }
        }

        int min_difference = std::numeric_limits<int>::max();

        for (auto pair : pairs) {
            int difference = std::abs(pair.first - pair.second);
            if (difference < min_difference) {
                min_difference = difference;
                rows = pair.first;
                cols = pair.second;
            }
        }
    }


    for (int i = 0; i < rows; i ++) {
        std::vector<int> row(cols, 0);
        int offset = cols * i;
        for (int j = 0; j < cols; j++) {
            row[j] = j + 1 + offset;
        }
        if (i % 2 != 0) std::reverse(row.begin(), row.end());
        ans.push_back(row);
    }
    return ans;
}

void print_matrix(std::vector<std::vector<int>> matrix, char sep){
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        std::vector<int> row = matrix[i];
        for (int j = 0; j < cols; j++) {
            std::cout << row[j] << sep;
        }
        std::cout << '\n';
    }
}

void write_matrix(std::vector<std::vector<int>> matrix, char sep, std::string file_path) {
    std::ofstream out;
    out.open(file_path);
    if (out.is_open()) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {
            std::vector<int> row = matrix[i];
            for (int j = 0; j < cols; j++) {
                out << row[j] << sep;
            }
            out << '\n';
        }
    } else std::cerr << "Something went wrong";
}



void countFileStatistics(std::string file_path) {
    int n = read_number(file_path);
    std::vector<std::vector<int>> matrix = create_matrix(n);
    write_matrix(matrix, '\t', "/Users/mayakorablina/Yandex.Disk.localized/CodingProjects/cpp_course_2_sem/2023_2024_2nd_sem/week6/11_12_sem/problem3_matrix/answer.txt");
}

int main() {
    countFileStatistics("/Users/mayakorablina/Yandex.Disk.localized/CodingProjects/cpp_course_2_sem/2023_2024_2nd_sem/week6/11_12_sem/problem3_matrix/number.txt");
    return 0;
}