///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       14.02.2024
///
/// TASK DESCRIPTION
///
///Car
///Define a Car struct with private attributes
///for year of manufacture (year), color (color),
///number of doors (count_doors), fuel level
///(fuel_level) and mileage (mileage).
///Implement a constructor to initialize these
///attributes. Fuel level and mileage must be
///the default values are 50.0 and 0.0 respectively.
///Implement the drive(double distance) method.
///which reduces the fuel level depending on
///distance traveled and increases mileage.
///  Assume that the car consumes 1 liter
///  fuel for 10 km.
///Implement the refuel(double amount) method to
///  add fuel to the tank.
///Add a stop() method that prints a message
///that the car has been stopped.
///Implement an info() method that prints information
///about the car: year of manufacture, color, number of doors,
///fuel level and mileage.
///Implement methods to change colors
///car and obtaining current color values,
///fuel level and mileage.
///In the main function, create several Car objects with different characteristics.
///Test all class methods to make sure they work correctly. Try walking some distance, refueling the car, changing its color and then displaying information about it.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>


struct Car {
private:
    int year;
    std::string colour;
    int count_doors;
    double fuel_level;
    double mileage;

public:
    Car(int y, std::string c, int d, double f = 50.0, double dis = 0.0) {
        year = y;
        colour = std::move(c);
        count_doors = d;
        fuel_level = f;
        mileage = dis;

        if (count_doors > 4) std::cout << "Ohhhh, nice car man!" << '\n';
    }

    void info() {
        std::cout << year << ' ' << colour << ' ' << count_doors << ' ' << fuel_level << ' ' << mileage << '\n';
    }

    void drive(double distance){
        if (fuel_level >= distance / 10){
            fuel_level -= distance / 10;
            mileage += distance;
        }
        else{
            std::cout << "Car does not have enough fuel for the distance. It drove " << fuel_level * 10 << " kilometers" << '\n';
            mileage += fuel_level * 10;
            fuel_level = 0;
        }
    }

    void refuel(double amount){
        fuel_level += amount;
    }

    void stop(){
        std::cout << "The car has been stopped" << '\n';
    }

    void change_colour(std::string c){
        colour = std::move(c);
    }

    std::string get_colour(){
        return colour;
    }

    double get_fuel_level(){
        return fuel_level;
    }

    double get_mileage(){
        return mileage;
    }
};

int main() {
    Car car1(2010, "black", 5);
    car1.info();
    Car car2(2022, "white", 3);
    car2.info();

    car1.change_colour("Seriy");
    car1.drive(100000);
    car1.refuel(1);
    double current_fuel = car1.get_fuel_level() + car2.get_fuel_level();
    std::cout << current_fuel << '\n';

    for (int i = 0; i < 10; i++){
        car2.drive(10);
        std::cout << car2.get_mileage() << ' ';
    }
    std::cout << '\n';

    car1.info();
    car2.info();
    car1.stop(), car2.stop();

    return 0;
}