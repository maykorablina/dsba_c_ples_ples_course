#include <iostream>
#include <vector>
#include "string"
/*
You work as an analyst in a company that sells electronics. You are provided 
with monthly sales of products for a year in the form of a vector, where each 
element of the vector represents the sales amount for a month. Your task is 
to analyze the data and perform the following operations:

Find the total sales volume for the year.
Determine the month with the maximum sales volume. If there are multiple months 
with the maximum sales, output the first one.
Calculate the average monthly sales.
Determine whether the sales in each month exceed the average monthly sales. 
For each month, output true or false accordingly.
Find the number of months with sales below the average.

Input Data
Vector std::vector<int> sales = {12000, 15000, 13000, 19000, 17000, 16000, 
                                 18000, 21000, 20000, 17000, 22000, 19000};, 
where each element represents the sales amount for a month.

Tasks to Implement
Implement a function to calculate the total sales volume for the year.
Implement a function to find the month with the maximum sales volume.
Calculate the average monthly sales.
Determine whether the sales in each month exceed the average monthly sales, 
and output the corresponding true or false values.
Find the number of months with sales below the average.

Total sales volume for the year: 204000
Month with maximum sales volume: 11
Average monthly sales: 17000
Sales above average: false false false true true false true true true true true true
Number of months with sales below average: 3
*/

int maximum(std::vector<int> sales) {
    int m = sales[0];
    for (int i = 1; i < sales.size(); i++) {
        if (sales[i] > m) m = sales[i];
    }
    return m;
}

int pt1(std::vector<int> sales){
    int sum = 0;
    for (int i = 0; i < sales.size(); ++i) {
        sum += sales[i];
    }
    return sum;
}

int pt2(std::vector<int> sales){
    int m = maximum(sales);
    int counter = 0;
    for (int i = 0; i < sales.size(); i++) {
        if (sales[i] == m){
            counter++;
        }
    }
    return counter;
}

int pt3(std::vector<int> sales){
    return (pt1(sales)) / sales.size();
}

int pt21(std::vector<int> sales){
    int m = pt3(sales);
    int counter = 0;
    for (int i = 0; i < sales.size(); i++) {
        if (sales[i] < m){
            counter++;
        }
    }
    return counter;
}



std::vector<bool> pt4(std::vector<int> sales) {
    int a = pt3(sales);
    std::vector<bool> bool_data(sales.size(), false);
    for (int i = 0; i < bool_data.size(); i++) {
        if (sales[i] > a) {
            bool_data[i] = true;
        }
    }
    return bool_data;
}

std::string vac_to_string(std::vector<int> sales) {
    int avg = pt3(sales);
    std::vector<bool> b = pt4(sales);
    std::string ans = "";
    for (int i = 0; i < b.size(); i++) {
        if (sales[i] > avg) {
            ans += "true";
            ans += " ";
        }
        else {
            ans += "false";
            ans += " ";
        }
    }
    return ans;
}

void print_data(std::vector<int> sales) {
    std::cout << "Total sales volume for the year: " << pt1(sales) << '\n';
    std::cout << "Month with maximum sales volume: " << pt2(sales) << '\n';
    std::cout << "Average monthly sales: " << pt3(sales) << '\n';
    std::cout << "Sales above average: " << vac_to_string(sales) << '\n';
    std::cout << "Number of months with sales below average: " << pt21(sales) << '\n';
}

int main() {
    std::vector<int> sales = {12000, 15000, 13000, 19000, 17000, 16000,
                            18000, 21000, 20000, 17000, 22000, 19000};
    print_data(sales);
    return 0;
}