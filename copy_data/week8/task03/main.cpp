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


struct Student {
    std::string name;
    int age{};
    double grade{};

    friend std::istream& operator>>(std::istream& in, Student& student) {
        in >> student.name >> student.age >> student.grade;
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Student& student) {
        out << "Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade;
        return out;
    }
};

int countLines(const std::string& filePath){
    std::ifstream input(filePath);
    if (!input.is_open()){
        std::cout << "Aboba ne rabotaet\n";
        return 0;
    }
    else std::cout << "Zae... vse norm\n";

    std::string str;
    int counter = 0;
    while(std::getline(input, str)) counter++;

    input.close();
    return counter;
}

void readRecordsFromFile(const std::string& filePath, std::vector<Student>& students){
    std::ifstream input(filePath);
    if (!input.is_open()){
        std::cout << "Aboba ne rabotaet\n";
        return;
    }
    else std::cout << "Zae... vse norm\n";

    unsigned line_count = countLines(filePath);
    std::cout << line_count << '\n';

    for (int i = 0; i < line_count; i++){
        Student student;
        input >> student;
        students.push_back(student);
    }

    input.close();
}

void addRecord(std::vector<Student>& students){
    Student student;
    std::cin >> student;
    students.push_back(student);
}

void deleteRecord(std::vector<Student>& students, int index){
    students.erase(students.begin() + index - 1);
}

void displayRecords(std::vector<Student>& students){
    for (auto student : students){
        std::cout << "Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade << '\n';
    }
}

void writeRecordsToFile(const std::string& filePath, std::vector<Student>& students){
    std::ofstream output(filePath);
    if (!output.is_open()){
        std::cout << "Aboba ne rabotaet";
        return;
    }
    else std::cout << "Zae... vse norm";

    for (auto student : students){
        output << student;
    }

    output.close();
}

int main() {
    std::vector<Student> students;

    readRecordsFromFile("/Users/senya/CLionProjects/Plusi dla loxov/week8/task03/students.txt", students);

    addRecord(students);
    deleteRecord(students, 1);
    displayRecords(students);

    writeRecordsToFile("/Users/senya/CLionProjects/Plusi dla loxov/week8/task03/updated_students.txt", students);

    return 0;
}
