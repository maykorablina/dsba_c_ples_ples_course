#include <iostream>


bool IsPasswordValid(std::string str){

    int counter = 0, len = str.length();
    bool counter_arr[4] = {false, false, false, false};

    /*is length of the str less than 8 or bigger than 14*/
    if (len < 8 or len > 14) return false;

    for (int i = 0; i < len; i++){

        /*is char from ASCII table with cod from 33 to 127*/
        if ((int) str[i] < 33 or (int) str[i] > 127) return false;

        /*Is the char an upper alpha?*/
        if (not counter_arr[0] and isupper(str[i])){
            counter++;
            counter_arr[0] = true;
        }
        /*Is the char a lower alpha?*/
        else if (not counter_arr[1] and islower(str[i])){
            counter++;
            counter_arr[1] = true;
        }
        /*Is the char a number?*/
        else if (not counter_arr[2] and isdigit(str[i])){
            counter++;
            counter_arr[2] = true;
        }
        /*Is the char a symbol (not alpha and not number)?*/
        else if (not counter_arr[3] and not isalpha(str[i]) and not isdigit(str[i])){
            counter++;
            counter_arr[3] = true;
        }
    }

    if (counter >= 3) return true;

    return false;
}

int main()
{
    std::string str;
    std::cin >> str;

    if (IsPasswordValid(str)) std::cout << "YES";
    else std::cout << "NO";

    return 0;
}
