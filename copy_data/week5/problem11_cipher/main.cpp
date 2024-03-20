///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
///Develop a program to encrypt the content of a text file
/// using the Caesar cipher and write the encrypted content to another
/// file. For simplicity, shift each letter by 3 positions in the alphabet.
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>
#include <cctype> // For isalpha() and tolower()


char caesarCipher(char ch, int shift) {
    if (std::isalpha(ch)) {
        char base = std::islower(ch) ? 'a' : 'A';
        return (ch - base + shift) % 26 + base;
    }
    return ch;
}

void encryptFileContent(const std::string& inputFilePath, const std::string& outputFilePath, int shift = 3){
    std::ifstream input(inputFilePath);
    std::ofstream output(outputFilePath);
    if (!input.is_open() or !output.is_open()) {
        std::cout << "Error blinb";
        return;
    }
    else std::cout << "Vse norm" << ' ';

    std::string str;

    while (std::getline(input, str)){
        for (char c : str) output << caesarCipher(c, shift);
        output << '\n';
    }

    input.close();
    output.close();
}

int main() {
    encryptFileContent("/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem11_cipher/input.txt",
                       "/Users/senya/CLionProjects/C-plus-plus-2024/week5/problem11_cipher/encrypted.txt");
    return 0;
}
