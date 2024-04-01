#include <iostream>

/*
Imagine you are conducting a survey among the residents of a city on the topic
of "Your favorite season". The answers are collected in the form of a string, 
where each letter represents the respondent's choice:

W for winter,
S for spring,
U for summer, and
A for autumn.
Your task is to analyze the survey results using an std::vector<char> container 
to store the responses and STL algorithms to process them.

Tasks to Implement:
- Fill the std::vector<char> responses with the survey results.
- Use std::accumulate to count the total number of responses.
- Find the most popular season using a combination of std::count_if and 
  comparing the results.
- Use std::find_if to find the first response that chose summer (U).
Output the obtained results: the total number of responses, the most and least 
popular seasons, and the position of the first response choosing summer.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <map>

int main() {
    std::vector<char> responses = {'W', 'S', 'U', 'A', 'W', 'S', 'U',
                                   'A', 'S', 'U', 'A', 'W', 'S', 'U', 'A', 'W'};

    int total_responses = responses.size();

    std::map<char, int> season_counts;
    for (char season : {'W', 'S', 'U', 'A'}) {
        season_counts[season] = std::count_if(responses.begin(), responses.end(), [season](char response) {
            return response == season;
        });
    }

    auto most_popular = *std::max_element(season_counts.begin(), season_counts.end(),
                                          [](const auto& a, const auto& b) { return a.second < b.second; });
    auto least_popular = *std::min_element(season_counts.begin(), season_counts.end(),
                                           [](const auto& a, const auto& b) { return a.second < b.second; });

    auto first_summer = std::find_if(responses.begin(), responses.end(), [](char response) {
        return response == 'U';
    });
    int summer_position = first_summer != responses.end() ? std::distance(responses.begin(), first_summer) + 1 : -1;

    std::cout << "Total number of responses: " << total_responses << std::endl;
    std::cout << "Most popular season: " << most_popular.first << " with " << most_popular.second << " votes" << std::endl;
    std::cout << "Least popular season: " << least_popular.first << " with " << least_popular.second << " votes" << std::endl;
    std::cout << "Position of the first summer lover: " << summer_position << std::endl;

    return 0;
}

