#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>


/*
Create a program that manages a dictionary of terms and 
their definitions. Implement functionalities to read term-definition 
pairs from a file, store them in a data structure (e.g., map or 
unordered_map), allow users to look up definitions of terms, add new
 term-definition pairs, delete existing pairs, and save the dictionary 
 to a file.

Requirements:

Implement a data structure to represent the dictionary with terms as keys and their definitions as values.

Implement functions/methods to read term-definition pairs from a file and populate the dictionary.

Implement a function/method to look up the definition of a term in the dictionary and display it.

Implement a function/method to add a new term-definition pair to the dictionary.

Implement a function/method to delete an existing term-definition pair from the dictionary.

Implement a function/method to save the dictionary to a file.

Provide a user interface allowing users to interact with the dictionary (e.g., through a command-line interface or a simple graphical user interface).

Ensure error handling for file input/output operations and dictionary operations (e.g., handling invalid input, file not found, etc.).
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>

void loadDictionary(const std::string& filename, std::map<std::string, std::string>& dictionary) {
    std::ifstream inputFile(filename);
    if (!inputFile) {
        std::cerr << "Failed to open the file." << std::endl;
    } else{
        std::string line;
        while (std::getline(inputFile, line)) {
            for(int i = 0; i < line.length();i++) {
                if (line[i] == ' ') {
                    std::string w = line.substr(0, i);
                    std::string d = line.substr(i + 3);
                    dictionary[w] = d;
                    break;
                }
            }
        }
        inputFile.close();
    }
}

std::string capitalize(std::string str) {
    std::string ans = "";
    ans += static_cast<char>(std::toupper(str[0]));
    for (int i = 1; i < str.length(); i++) {
        ans += static_cast<char>(std::tolower(str[i]));
    }
    return ans;
}



struct Dictionary{
private:
    std::map<std::string, std::string> dictionary;
public:
    Dictionary(const std::string& path) {
        loadDictionary(path, dictionary);
    }
    void lookupTerm(const std::string& term) {
        std::string a = capitalize(term);
        auto it = dictionary.find(a);
        if (it != dictionary.end()) {
            std::cout << it->second << '\n';
        } else {
            std::cout << "\033[31m" << '"' << a << '"' << " is not in dictionary." << "\033[0m" << '\n';
        }
    }
    void addTerm(std::string word) {
        word = capitalize(word);
        auto it = dictionary.find(word);
        if (it != dictionary.end()) {
            std::cout << "\033[31m" << '"' << word << '"' << " is already in the dictionary." << "\033[0m" << '\n';
        } else {
            std::string definition;
            std::cout << "Enter the definition to " << word << ": ";
            std::cin >> definition;
            dictionary[word] = capitalize(definition);
            std::cout << "\033[32m" << '"' << word << '"' << " was successfully added to the dictionary." << "\033[0m" << '\n';
        }

    }
    void deleteTerm(const std::string term) {
        std::string a = capitalize(term);
        auto it = dictionary.find(a);
        if (it != dictionary.end()) {
            dictionary.erase(a);
            std::cout << "\033[32m" << '"' << a << '"' << " was successfully removed from the dictionary." << "\033[0m" << '\n';
        } else {
            std::cout << "\033[31m" << '"' << a << '"' << " is not in dictionary." << "\033[0m1" << '\n';
        }
    }
    void saveDictionary(const std::string& filename) {
        std::ofstream out(filename);
        if (!out) {
            std::cout << "\033[31m" << "Can't open the file." << '\n';
        } else{
            for (const auto& pair : dictionary) {
                out << pair.first << " - " << pair.second << '\n';
            }
            std::cout << "\033[32m" << "The dictionary was successfilly saved in " << filename << "\033[0m" << '\n';
            out.close();
        }
    }
};

int main() {
    std::string filename = "/Users/mayakorablina/Yandex.Disk.localized/CodingProjects/cpp_course_2_sem/2023_2024_2nd_sem/week8/15-16_sem/task04/dictionary.txt";
    std::string out = "/Users/mayakorablina/Yandex.Disk.localized/CodingProjects/cpp_course_2_sem/2023_2024_2nd_sem/week8/15-16_sem/task04/new_dictionary.txt";
    Dictionary dictionary(filename);
    int choice;
    std::string term;
    do {
        std::cout << "\nDictionary Application\n"
                  << "1. Look up a term\n"
                  << "2. Add a new term\n"
                  << "3. Delete a term\n"
                  << "4. Save dictionary to file\n"
                  << "5. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter the term to look up: ";
                std::cin >> term;
                dictionary.lookupTerm(term);
                break;
            case 2:
                std::cout << "Enter a new term: ";
                std::cin >> term;
                dictionary.addTerm(term);
                break;
            case 3:
                std::cout << "Enter the term to delete: ";
                std::cin >> term;
                dictionary.deleteTerm(term);
                break;
            case 4:
                dictionary.saveDictionary(out);
                break;
            case 5:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
        }
    } while (choice != 5);

    return 0;
}
