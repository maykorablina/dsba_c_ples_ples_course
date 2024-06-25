// Implement a class system to represent various
// geometric shapes and calculation of their area.

// Base class Shape:
// Contains the x and y coordinates of the shape's center.
// Declares the area() function to calculate area.
// Derived class Circle:
// Inherits Shape.
// Adds the radius property.
// Implements the area() function to calculate the area of a circle.
// Rectangle derived class:
// Inherits Shape.
// Adds width and height properties.
// Implements the area() function to calculate the area of a rectangle.

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <vector>


class Shape {
protected:
    double x, y;

public:
    Shape(double x, double y) : x(x), y(y) {
        std::cout << "Shape was created" << '\n';
    }

    virtual double area() const = 0;

    ~Shape() {
        std::cout << "Shape was destroyed" << '\n';
    }
};

class Circle : Shape {
private:
    double radius;

public:
    Circle(double x, double y, double r) : Shape(x, y), radius(r) {
        std::cout << "Circle was created" << '\n';
    }

    double area() const override {
        return M_PI * radius * radius;
    }

    ~Circle() {
        std::cout << "Circle was destroyed" << '\n';
    }
};

class Rectangle : Shape {
private:
    double width;
    double height;

public:
    Rectangle(double x, double y, double w, double h) : Shape(x, y), width(w), height(h) {
        std::cout << "Rectangle was created" << '\n';
    }

    double area() const override{
        return width * height;
    }

    ~Rectangle() {
        std::cout << "Rectangle was destroyed" << '\n';
    }
};

int main() {
    Circle circle(0, 0, 2);
    Rectangle rectangle(0, 0, 2, 4);
    std::cout << '\n';

    std::cout << "Area of the Circle in hereditary class of Shape is " << circle.area() << "\n"
                << "Area of the Rectangle in hereditary class of Shape is " << rectangle.area() << '\n';

    std::cout << '\n';

    return 0;
}