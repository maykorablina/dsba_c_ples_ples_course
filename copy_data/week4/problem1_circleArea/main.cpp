///////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem: Calculate the Area of a Circle
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Write a function `double circleArea(double radius)` that calculates and 
/// returns the area of a circle given its radius.
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>


double CircleArea(double radius){
    return M_PI * radius * radius;
}

int main() {
    double radius;
    std::cin >> radius;
    std::cout << CircleArea(radius);

    return 0;
}
