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
/////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <sstream>

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

//    main algorithm here
    std::vector<std::vector<int>> ans(rows, std::vector<int>(cols));
    int up = 0, down = rows - 1, left = 0, right = cols - 1;
    int val = 1;
    while (up <= down and left <= right) {
        for(int j = left; j <= right; j++) {
            ans[up][j] = val++;
        }
        up++;

        for(int j = up; j <= down; j++) {
            ans[j][right] = val++;
        }
        right--;
        if (up <= down) {
            for (int j = right; j >= left; j--) {
                ans[down][j] = val++;
            }
            down--;
        }

        if (left <= right) {
            for (int j = down; j >= up; j--) {
                ans[j][left] = val++;
            }
            left++;
        }
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


int main() {
    std::vector<std::vector<int>> matrix = create_matrix(read_number("/Users/mayakorablina/Yandex.Disk.localized/CodingProjects/cpp_course_2_sem/2023_2024_2nd_sem/week6/11_12_sem/problem4_snake/file.txt"));
    write_matrix(matrix, '\t', "/Users/mayakorablina/Yandex.Disk.localized/CodingProjects/cpp_course_2_sem/2023_2024_2nd_sem/week6/11_12_sem/problem4_snake/matrix.txt");
    return 0;
}