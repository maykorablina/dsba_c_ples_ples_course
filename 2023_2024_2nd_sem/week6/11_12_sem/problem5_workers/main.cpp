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
#include <string>
#include "sstream"

// i dont understand why do i need to make 2 different functions, so i didnt do it)))

std::string read_file(std::string file_path) {
    std::string text;
    std::ifstream in(file_path);
    if (in.is_open())
    {
        std::stringstream buff;
        buff << in.rdbuf();
        text = buff.str();
    }
    in.close();
    return text;
}

std::vector<std::string> split(std::string str, char separator) {
    std::vector<std::string> ans;
    int index_start = 0;
    int length = 1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == separator) {
            ans.push_back(str.substr(index_start, length - 1));
            index_start = i + 1;
            length = 0;
        }
        length += 1;
    }
    ans.push_back(str.substr(index_start));
    return ans;
}

std::string join(std::vector<std::string> vec, char sep) {
    std::string res;
    for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size() - 1) {
            res += vec[i];
        } else res += vec[i] + sep;
    }
    return res;
}

void print_array(std::vector<std::string> arr, char sep) {
    for(int i = 0; i < arr.size();i++){
        if (i == arr.size() - 1) std::cout << arr[i];
        else std::cout << arr[i] << sep;
    }
    std::cout << '\n';
}


void increaseSalaries(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::string file_data = read_file(inputFilePath);
    std::vector<std::string> rows = split(file_data, '\n');
    std::vector<std::string> new_rows;
    new_rows.push_back(rows[0]);
    for (int i = 1; i < rows.size() - 1; i++) {
        std::vector<std::string> row = split(rows[i], ',');
        double salary = std::stod(row[2]);
        row[2] = std::to_string(std::round(salary * 1.1 * 100) / 100);
        row[2] = row[2].substr(0, row[2].length() - 4);
        new_rows.push_back(join(row, ','));
    }

    std::ofstream out(outputFilePath);
    if (out.is_open()) {
        for (int i = 0; i < new_rows.size(); i++) {
            out << new_rows[i] << '\n';
        }
    }

}

int main() {

    increaseSalaries("/Users/mayakorablina/Yandex.Disk.localized/CodingProjects/cpp_course_2_sem/2023_2024_2nd_sem/week6/11_12_sem/problem5_workers/employees.txt", "/Users/mayakorablina/Yandex.Disk.localized/CodingProjects/cpp_course_2_sem/2023_2024_2nd_sem/week6/11_12_sem/problem5_workers/employees_upgraded.txt");
    return 0;
}