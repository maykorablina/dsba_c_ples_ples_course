/*
Create a programming task that involves designing a class hierarchy for geometric shapes, specifically
 circles and rectangles, with the capability to calculate their area. At the base of this hierarchy is
 an abstract class named `Shape`, which includes protected variables `x` and `y` representing the coordinates
 of the shape's center, and a pure virtual method `area()` for calculating the area. Derived from `Shape`
 are the classes `Circle` and `Rectangle`, each implementing the `area()` method according to their unique
 properties: radius for the circle and width and height for the rectangle. In the main function of the program,
 instances of a circle and a rectangle are to be created, their areas calculated, and the results displayed on
 the screen. Afterward, the allocated memory should be properly freed. The task is to write the necessary
 classes and the main function, adhering to the principles of inheritance and polymorphism in C++.
 */

#include <cmath>
#include <iostream>
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
