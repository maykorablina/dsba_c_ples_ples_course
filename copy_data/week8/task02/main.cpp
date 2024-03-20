///Imagine you are conducting a survey among the residents of a city on the topic
///of "Your favorite season". The answers are collected in the form of a string,
///where each letter represents the respondent's choice:
///
///W for winter,
///S for spring,
///U for summer, and
///A for autumn.
///Your task is to analyze the survey results using an std::vector<char> container
///to store the responses and STL algorithms to process them.
///
///Tasks to Implement:
///- Fill the std::vector<char> responses with the survey results.
///- Use std::accumulate to count the total number of responses.
///- Find the most popular season using a combination of std::count_if and
///  comparing the results.
///- Use std::find_if to find the first response that chose summer (U).
///Output the obtained results: the total number of responses, the most and least
///popular seasons, and the position of the first response choosing summer.

#include <iostream>
#include <map>


int main() {
    std::vector<char> responses = {'W', 'S', 'U', 'A', 'W', 'S', 'U',
                                 'A', 'S', 'U', 'A', 'W', 'S', 'U', 'A', 'W'};

    int w = std::count_if(responses.begin(), responses.end(), [](char c){return c == 'W';});
    int s = std::count_if(responses.begin(), responses.end(), [](char c){return c == 'S';});
    int u = std::count_if(responses.begin(), responses.end(), [](char c){return c == 'U';});
    int a = std::count_if(responses.begin(), responses.end(), [](char c){return c == 'A';});
    int first_u = std::find_if(responses.begin(), responses.end(),
                               [](char c){return c == 'U';}) - responses.begin();

    std::cout << "Amount of responses: " << responses.size() << '\n'
                << "The most popular season: " << std::max({w, s, u, a}) << '\n'
                << "The first response that chose summer: " << first_u + 1;

    return 0;
}
