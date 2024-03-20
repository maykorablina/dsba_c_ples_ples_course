///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Increment Value
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `void increment(int &value)` 
/// that increments the value of 
/// the passed integer by 1.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

template<typename T>
T increment(T num){
    return num + 1;
}

int main()
{
    std::cout << increment(1) << '\n'
                << increment(12.32442) << '\n'
                << increment("Hello, world!");

    return 0;
}
