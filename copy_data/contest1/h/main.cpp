#include <iostream>


int main()
{
    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day, month, year;
    std::cin >> day >> month >> year;
    if (month != 2){
        if (month != 12){
            if (day + 1 < arr[month - 1])
                day += 2;
            else if (day + 1 > arr[month - 1])
                day = 2, month++;
            else day = 1, month++;
        }
        else{
            if (day + 1 < arr[month - 1])
                day += 2;
            else if (day + 1 > arr[month - 1])
                day = 2, month = 1, year++;
            else day = 1, month = 1, year++;
        }
    }
    else{
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
            if (day + 1 < arr[month - 1] + 1)
                day += 2;
            else if (day + 1 > arr[month - 1] + 1)
                day = 2, month++;
            else day = 1, month++;
        }
        else {
            if (day + 1 < arr[month - 1])
                day += 2;
            else if (day + 1 > arr[month - 1])
                day = 2, month++;
            else day = 1, month++;
        }
    }

    std::cout << day << ' ' << month << ' ' << year;

    return 0;
}
