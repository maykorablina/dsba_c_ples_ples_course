#include <iostream>
#include <fstream>


//void TryToOpen(){
//    std::ifstream file;
//    file.open("/Users/senya/CLionProjects/C-plus-plus-2024/contest3/a/input.txt");
//
//    if (file.is_open()) std::cout << "Open";
//    else std::cout << "Not working";
//
//    file.close();
//}

void CheckText(std::ifstream &file, int* count_lines, int* count_words, int* count_letters){
    int counter = 0;
    std::string str;

    while(std::getline(file, str)){
        (*count_lines)++;
        if (!str.empty()) {
            for (char c : str) {
                if (isalpha(c)) {
                    (*count_letters)++;
                    counter++;
                }
                else if (counter > 0) {
                    (*count_words)++;
                    counter = 0;
                }
            }

            if (counter > 0) {
                (*count_words)++;
                counter = 0;
            }
        }
    }
}

int main()
{
    std::ifstream file("input.txt");
    int lines = 0, words = 0, letters = 0;

    CheckText(file, &lines, &words, &letters);

    std::cout << "Input file contains:" << '\n'
              << letters << " letters" << '\n'
              << words << " words" << '\n'
              << lines << " lines";

    file.close();
    return 0;
}