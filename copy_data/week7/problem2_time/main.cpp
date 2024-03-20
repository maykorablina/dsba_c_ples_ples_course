///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       14.02.2024
///
/// TASK DESCRIPTION
///
///Describe the “Time” structure with three fields: hours, minutes
///        and seconds. Define a subtraction operation such that
///the result is an object of type time containing
///        how much time is between the first and second event. If
///        the second event is later than the first, the answer should be equal to
///zero, otherwise return a time structure containing the difference
///between these events (hours, minutes, seconds).
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>


struct Time{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int event1_hours, int event1_minutes, int event1_seconds,
         int event2_hours, int event2_minutes, int event2_seconds){

        if (event2_hours > event1_hours or
            (event2_hours == event1_hours and event2_minutes > event1_minutes) or
            (event2_hours == event1_hours and event2_minutes == event1_minutes and event2_seconds > event1_seconds)){

            hours = 0;
            minutes = 0;
            seconds = 0;
            print_info();
            std::cout << "The second event is later than first" << "\n\n";
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
            print_info();
            std::cout << '\n';
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

int main() {
    Time events1(4, 34, 50, 3, 0, 0);
    Time events2(0, 15, 43, 18, 12, 29);

    return 0;
}
