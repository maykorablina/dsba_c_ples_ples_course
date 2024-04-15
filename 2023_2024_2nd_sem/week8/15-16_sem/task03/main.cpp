#include <iostream>

/*
You are tasked with creating a program to manage a database 
of students' information. Each student record consists of the 
following fields: name, age, and grade. You need to implement 
a structure to represent a student record, including various 
overloaded operators for comparison and input/output operations.

In the main program, you should provide functionality to read 
student records from a file, add new records, delete existing 
records, modify records, and display all records. Additionally, 
you should implement the ability to save the updated database 
to a file.

Furthermore, you are required to store the collection of student 
records in a container such as a vector or any other appropriate 
container provided by the Standard Template Library (STL).

Your program should support the following operations:

Reading student records from a file and storing them in the database.
Adding a new student record to the database.
Deleting an existing student record from the database.
Modifying the information of an existing student record.
Displaying all student records.
Saving the updated database to a file.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "iostream"
#include "sstream"
#include "fstream"

struct Student {
    std::string name;
    int age;
    double grade;

    Student(std::string n = "q", int a = 9, double g = 90.0): name(n), age(a), grade(g) {}

    friend std::istream& operator>>(std::istream& in, Student& student) {
        in >> student.name >> student.age >> student.grade;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Student& student) {
        out << "Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade;
        return out;
    }
};

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

void print_array(std::vector<std::string> v, char sep){
    for (int i = 0; i < v.size(); i++){
        if (i == v.size() - 1) std::cout << v[i];
        else std::cout << v[i] << sep;
    }
    std::cout << '\n';
}

void readRecordsFromFile(std::string path, std::vector<Student>& students) {
    std::string data = read_file(path);
    std::vector<std::string> string_data = split(data, '\n');
    for (int i = 0; i < string_data.size(); i++) {
        std::vector<std::string> row = split(string_data[i], ' ');
        Student stud = Student(row[0], std::stoi(row[1]), std::stod(row[2]));

        students.push_back(stud);
    }
}

void displayRecords(std::vector<Student> students) {
    for (int i = 0; i < students.size(); i++) {
        std::cout << students[i] << '\n';
    }
}

void addRecord(std::vector<Student>& students) {
    Student s;
    std::cin >> s;
    students.push_back(s);

}

void deleteRecord(std::vector<Student>& students, int index) {
    students.erase(students.begin() + index);
//    vec.erase(std::remove(vec.begin(), vec.end(), value_to_remove), vec.end());
}

void saveDatabase(std::vector<Student>& students, std::string path) {
    std::ofstream out(path);
    if (out.is_open()) {
        for (int i = 0; i < students.size(); i++) {
            out << students[i].name << ' ' << students[i].age << ' ' << students[i].grade <<'\n';
        }
    }
}

int main() {
    std::vector<Student> students;
    readRecordsFromFile("/Users/mayakorablina/Yandex.Disk.localized/CodingProjects/cpp_course_2_sem/2023_2024_2nd_sem/week8/15-16_sem/task03/students.txt", students);
    addRecord(students);
    displayRecords(students);
    saveDatabase(students, "/Users/mayakorablina/Yandex.Disk.localized/CodingProjects/cpp_course_2_sem/2023_2024_2nd_sem/week8/15-16_sem/task03/output.txt");

    return 0;
}
