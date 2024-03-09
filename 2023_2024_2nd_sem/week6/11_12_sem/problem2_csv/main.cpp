///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Create program to read data from a CSV file (comma separated)
/// and calculate the average value in each column. Separate into function
///
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include "sstream"
#include "string"
#include "vector"
#include <regex>


bool check_numbers(std::vector<std::string> vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (!std::regex_search(vec[0], std::regex("^[0-9]+$"))) return false;
    }
    return true;
}

void write_to_file(std::string file_path, std::string content) {
    std::ofstream out;
    out.open(file_path);
    if (out.is_open()) {
        out << content;
    }
    out.close();
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

void read_csv(std::string file_path) {
    std::string line;
    std::string text;
    std::ifstream in(file_path);
    if (in.is_open())
    {
        std::stringstream buff;
        buff << in.rdbuf();
        text = buff.str();
    }
    in.close();
    std::vector<std::string> rows = split(text, '\n');
    int cols_number = split(rows[0], ',').size();
    int sums_by_cols[cols_number];

    std::fill(sums_by_cols, sums_by_cols+cols_number, 0);

    for (int i = 0; i < rows.size(); i++) {
        std::vector<std::string> row = split(rows[i], ',');
        if (!check_numbers(row)) continue;
        for (int k = 0; k < cols_number; k++) {
            sums_by_cols[k] += std::stoi(row[k]);
        }
    }
    std::string ans;
    for (int i = 0; i < cols_number; i++) {
        ans += "Sum of column " + std::to_string(i + 1) + " is " + std::to_string(sums_by_cols[i]) + '\n';
    }
    write_to_file("/Users/mayakorablina/Yandex.Disk.localized/CodingProjects/cpp_course_2_sem/2023_2024_2nd_sem/week6/11_12_sem/problem2_csv/answer.txt", ans);
}

int main() {
    read_csv("/Users/mayakorablina/Yandex.Disk.localized/CodingProjects/cpp_course_2_sem/2023_2024_2nd_sem/week6/11_12_sem/problem2_csv/numbers.csv");

}