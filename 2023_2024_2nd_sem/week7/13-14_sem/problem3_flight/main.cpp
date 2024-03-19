///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Describe the “Flight” structure with flight identifier fields,
/// departure airport, destination airport and departure time
/// (structure “Time”). Write a function that takes as input
/// vector of flights and airport name displaying information
/// first about all flights arriving at the specified airport, and then
/// about all flights departing from this airport.
///
#include "iostream"
#include <fstream> 
struct Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time (int h=0, int m=0, int s = 0) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    int get_seconds(){
        return hours * 3600 + minutes * 60 + seconds;
    }

    Time time_difference(Time t2){
        int diff = this->get_seconds() - t2.get_seconds();
        if (diff < 0) return Time(0, 0, 0);
        else {
            return Time(diff / 3600, (diff % 3600) / 60, diff % 60);
        }
    }
    void print_time() {
        std::cout << hours << ' ' << minutes << ' ' << seconds << '\n';
    }

    std::string time_as_string(){
        std::string h = std::to_string(hours);
        std::string m = std::to_string(minutes);
        std::string s = std::to_string(seconds);
        if (h.length() == 1) {
            h = "0" + h;
        }
        if (m.length() == 1) {
            m = "0" + m;
        }
        if (s.length() == 1) {
            s = "0" + s;
        }
        std::string a = h + ":" + m + ":" + s;
        return a;
    }
};

struct Flight{
private:
    std::string departure;
    std::string arrival;
    Time departure_time;
    Time arrival_time;
public:
    Flight(std::string d, std::string a, std::vector<int> time_data){
        departure = d;
        arrival = a;
        departure_time = Time(time_data[0], time_data[1], time_data[2]);
        arrival_time = Time(time_data[3], time_data[4], time_data[5]);
    }
    void print_flight_info(){
        std::string a = "Departure airport: " + departure + '\n';
        a += "Departure time: " + departure_time.time_as_string() + '\n';
        a += "Arrival airport: " + arrival + '\n';
        a += "Arrival time: " + arrival_time.time_as_string() + '\n';
        std::cout << a;
    }
    std::string getDepartureAir(){
        return departure;
    }
    std::string getArrivalAir(){
        return arrival;
    }
};

void get_departure_info(std::vector<Flight> info, std::string dep_air){
    for (int i = 0; i < info.size(); i++) {
        if (info[i].getDepartureAir() == dep_air){
            info[i].print_flight_info();
            std::cout << '\n';
        }
    }
}

void get_arrival_info(std::vector<Flight> info, std::string arr_air){
    for (int i = 0; i < info.size(); i++) {
        if (info[i].getArrivalAir() == arr_air){
            info[i].print_flight_info();
            std::cout << '\n';
        }
    }
}

int main() {
    std::vector<Flight> flights = {
            {"NYC", "LAX", {8, 30, 0, 11, 45, 0}},
            {"BOS", "DFW", {7, 0, 0, 10, 30, 0}},
            {"ORD", "SEA", {9, 15, 0, 11, 45, 0}},
            {"DFW", "PHX", {5, 45, 0, 7, 30, 0}},
            {"ATL", "DEN", {6, 0, 0, 8, 15, 0}},
            {"NYC", "DFW", {11, 30, 0, 19, 45, 0}},
            {"SFO", "LAS", {14, 0, 0, 15, 30, 0}},
            {"MCO", "EWR", {12, 15, 0, 14, 45, 0}},
            {"NYC", "DFW", {13, 30, 0, 15, 5, 0}}};
    std::cout << "Departure from NYC:\n";
    get_departure_info(flights, "NYC");
    std::cout << "Arrival from DFW:\n";
    get_arrival_info(flights, "DFW");
    return 0;
}
