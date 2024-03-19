///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       14.02.2024
///
/// TASK DESCRIPTION
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
/*
Car
Define a Car struct with private attributes
for year of manufacture (year), color (color),
number of doors (count_doors), fuel level
(fuel_level) and mileage (mileage).
Implement a constructor to initialize these
attributes. Fuel level and mileage must be
the default values are 50.0 and 0.0 respectively.
Implement the drive(double distance) method.
which reduces the fuel level depending on
distance traveled and increases mileage.
  Assume that the car consumes 1 liter
  fuel for 10 km.
Implement the refuel(double amount) method to
  add fuel to the tank.
Add a stop() method that prints a message
that the car has been stopped.
Implement an info() method that prints information
about the car: year of manufacture, color, number of doors,
fuel level and mileage.
Implement methods to change colors
car and obtaining current color values,
fuel level and mileage.
In the main function, create several Car objects with different characteristics.
Test all class methods to make sure they work correctly. Try walking some distance, refueling the car, changing its color and then displaying information about it.
*/

#include <string>

struct Car {
private:
    int year;
    std::string color;
    int count_doors;
    double fuel_level;
    double mileage;

public:
    Car(int y, std::string c, int doors, double fuel = 50.0, double m = 0.0){
        year = y;
        color = c;
        count_doors = doors;
        fuel_level = fuel;
        mileage = m;
    }

    void drive(double distance) {
        mileage += distance;
        fuel_level -= distance / 10;
    }

    void refuel(double amount) {
        fuel_level += amount;
    }

    void stop(){
        std::cout << "The car has been stopped.\n";
    }

    void change_color(std::string new_color) {
        color = new_color;
    }

    std::string getColor() const {
        return color;
    }

    double getFuelLevel() const {
        return fuel_level;
    }
    double getMileage() const {
        return mileage;
    }

    void info(){
        std::cout << year << ' ' << color << ' ' << count_doors << ' ' << fuel_level << ' ' << mileage << '\n';
    }
};

int main(){
    Car car1(1990, "black", 4);
    car1.refuel(100.0);
    car1.drive(100.0);
    car1.info();
    return 0;
}