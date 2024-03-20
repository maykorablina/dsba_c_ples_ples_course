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

#include <iostream>
#include <iomanip>
#include <vector>


struct Time{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(){
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    void update_time(int event1_hours, int event1_minutes, int event1_seconds,
         int event2_hours, int event2_minutes, int event2_seconds){

        if (event2_hours > event1_hours or
            (event2_hours == event1_hours and event2_minutes > event1_minutes) or
            (event2_hours == event1_hours and event2_minutes == event1_minutes and event2_seconds > event1_seconds)){

            hours = 0;
            minutes = 0;
            seconds = 0;
            std::cout << "The second event is later than first" << '\n';
        }
        else {
            hours = event1_hours - event2_hours;

            if (event1_minutes < event2_minutes) {
                minutes = 60 + event1_minutes - event2_minutes;
                hours--;
            }
            else minutes = event1_minutes - event2_minutes;

            if (event1_seconds < event2_seconds) {
                if (minutes > 0) {
                    seconds = 60 + event1_seconds - event2_seconds;
                    minutes--;
                }
                else {
                    seconds = 60 + event1_seconds - event2_seconds;
                    minutes = 59;
                    hours--;
                }
            }
            else seconds = event1_seconds - event2_seconds;
        }
    }

    void print_info(){
        std::cout << hours << " hours " << minutes << " minutes " << seconds << " seconds between events" << '\n';
    }

    std::vector<int> get_info(){
        std::vector<int> array{hours, minutes, seconds};
        return array;
    }
};

struct Flight{
public:
    std::string departure_airport;
    std::string destination_airport;
    std::vector<int> departure_time;
    std::vector<int> destination_time;
    Time flight_time;

    Flight(std::string dep_airport, std::string dest_airport, std::vector<int> dep_time, std::vector<int> dest_time){
        departure_airport = dep_airport;
        destination_airport = dest_airport;
        departure_time = dep_time;
        destination_time = dest_time;
        flight_time.update_time(destination_time[0], destination_time[1], destination_time[2],
                                departure_time[0], departure_time[1], departure_time[2]);
    }

    void info(std::string flag){
        std::string dep_time = std::to_string(departure_time[0]) + ":" +
                std::to_string(departure_time[1]) + ":" + std::to_string(departure_time[2]);
        std::string dest_time = std::to_string(destination_time[0]) + ":" +
                std::to_string(destination_time[1]) + ":" + std::to_string(destination_time[2]);

        std::vector<int> array = flight_time.get_info();
        std::string f_time = std::to_string(array[0]) + ":" + std::to_string(array[1]) + ":" + std::to_string(array[2]);
        if (flag == "dest")
            std::cout << std::setw(20) << departure_airport << std::setw(20) <<
                        dep_time << std::setw(20) << dest_time << std::setw(20) << f_time << "\n";
        else
            std::cout << std::setw(20) << destination_airport << std::setw(20) <<
                      dep_time << std::setw(20) << dest_time << std::setw(20) << f_time << "\n";
    }
};

std::vector<Flight> create_flight_table(std::vector<std::vector<std::vector<int>>> flights,
                                        std::vector<std::vector<std::string>> airports){
    int length = airports.size();
    std::vector<Flight> table;

    for (int i = 0; i < length; i++){
        table.emplace_back(airports[i][0], airports[i][1],
                               flights[i][0], flights[i][1]);
    }

    return table;
}

void print_table(std::vector<Flight> table, std::string name){
    std::cout << "For " << name << '\n' << "Arrivals:\n";
    int counter = 0;

    for (auto el : table){
        if (el.destination_airport == name) {
            el.info("dest");
            counter++;
        }
    }

    if (counter == 0) std::cout << "No arrivals\n";

    std::cout << "\nDepartures:\n";
    counter = 0;

    for (auto el : table){
        if (el.departure_airport == name) {
            el.info("dep");
            counter++;
        }
    }

    if (counter == 0) std::cout << "No departures\n";
    std::cout << "\n\n";
}

int main() {
    std::vector<std::vector<std::vector<int>>> flights {{{1, 32, 45}, {4, 5, 54}}, {{14, 0, 0}, {19, 12, 0}}};
    std::vector<std::vector<std::string>> airports {{"Moscow", "Vladivostok"}, {"Sydney", "Brazilia"}};

    std::vector<Flight> table = create_flight_table(flights, airports);

    std::cout << std::setw(20) << "airport" << std::setw(20) << "dep time" << std::setw(20) <<
                "arr time" << std::setw(20) << "flight time\n";

    std::vector<std::string> all_airports;
    for (auto el : airports){
        for (auto j : el) {
            if (std::find(all_airports.begin(), all_airports.end(), j) == all_airports.end()) {
                all_airports.push_back(j);
            }
        }
    }
    for (auto name : all_airports) print_table(table, name);
    
    return 0;
}