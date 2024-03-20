///You work as an analyst in a company that sells electronics. You are provided
///with monthly sales of products for a year in the form of a vector, where each
///element of the vector represents the sales amount for a month. Your task is
///to analyze the data and perform the following operations:
///
///Find the total sales volume for the year.
///Determine the month with the maximum sales volume. If there are multiple months
///with the maximum sales, output the first one.
///Calculate the average monthly sales.
///Determine whether the sales in each month exceed the average monthly sales.
///For each month, output true or false accordingly.
///Find the number of months with sales below the average.
///
///Input Data
///Vector std::vector<int> sales = {12000, 15000, 13000, 19000, 17000, 16000,
///                                 18000, 21000, 20000, 17000, 22000, 19000};,
///where each element represents the sales amount for a month.
///
///Tasks to Implement
///Implement a function to calculate the total sales volume for the year.
///Implement a function to find the month with the maximum sales volume.
///Calculate the average monthly sales.
///Determine whether the sales in each month exceed the average monthly sales,
///and output the corresponding true or false values.
///Find the number of months with sales below the average.
///
///Total sales volume for the year: 204000
///Month with maximum sales volume: 11
///Average monthly sales: 17000
///Sales above average: false false false true true false true true true true true true
///Number of months with sales below average: 3

#include <iostream>
#include <numeric>


int total_value(std::vector<int> arr){
    return std::reduce(arr.begin(), arr.end());
}

int average_value(std::vector<int> arr){
    return std::reduce(arr.begin(), arr.end()) / arr.size();
}

int index_of_maximum(std::vector<int> arr){
    return std::max_element(arr.begin(), arr.end()) - arr.begin() - 1;
}

int main() {
    std::vector<std::string> months = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"};
    std::vector<int> sales = {12000, 15000, 13000, 19000, 17000, 16000,
                            18000, 22000, 20000, 17000, 22000, 19000};

    int total = total_value(sales);
    int average = average_value(sales);
    int max_index = index_of_maximum(sales);
    int counter = 0;

    std::cout << "Total sales volume for the year: " << total << '\n';
    std::cout << "Month with maximum sales volume: " << months[max_index] << '\n';
    std::cout << "Average monthly sales: " << average << '\n';

    std::cout << "Sales above average: ";
    for (int i = 0; i < 12; i++) {
        if (sales[i] > average) std::cout << "true ";
        else {
            std::cout << "false ";
            counter++;
        }
    }
    std::cout << '\n';

    std::cout << "Number of months with sales below average: " << counter;

    return 0;
}