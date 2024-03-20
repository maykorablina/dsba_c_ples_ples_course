/*******************************************************************************
 * Workshop 2/Task 1
 * Studying properties of some basic datatypes.
 *
 * Use operator sizeof to explore size of all important basic datatypes:
 *  char, short, int, long, long long, double, bool
 *
 * For storing results use named variables of size_t for some types from the
 * list above.
 * Also, try to create complex expressions for output formatted results to
 * std::cout.
 *
 ******************************************************************************/

#include <iostream>

int main()
{
    size_t sizeofchar = sizeof(char);
    size_t sizeofshort = sizeof(short);
    size_t sizeofint = sizeof(int);
    size_t sizeoflong = sizeof(long);
    size_t sizeoflonglong = sizeof(long long);
    size_t sizeofdouble = sizeof(double);
    size_t sizeofbool = sizeof(bool);

    std::cout << "Size of char is " << sizeofchar << " byte" << "\n"
            << "Size of short is " << sizeofshort << " bytes" << "\n"
            << "Size of int is " << sizeofint << " bytes" << "\n"
            << "Size of long is " << sizeoflong << " bytes" << "\n"
            << "Size of long long is " << sizeoflonglong << " bytes" << "\n"
            << "Size of double is " << sizeofdouble << " bytes" << "\n"
            << "Size of bool is " << sizeofbool << " bytes" << "\n";

    return 0;
}
