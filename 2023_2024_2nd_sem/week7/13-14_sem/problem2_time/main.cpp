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
Describe the “Time” structure with three fields: hours, minutes
and seconds. Define a subtraction operation such that
the result is an object of type time containing
how much time is between the first and second event. If
the second event is later than the first, the answer should be equal to
zero, otherwise return a time structure containing the difference
between these events (hours, minutes, seconds).
*/

struct Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time (int h, int m, int s = 0) {
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
};


int main() {

    Time t2(1, 3, 10);
    Time t1(10, 10, 10);
    Time a = t1.time_difference(t2);
    a.print_time();
    return 0;
}
