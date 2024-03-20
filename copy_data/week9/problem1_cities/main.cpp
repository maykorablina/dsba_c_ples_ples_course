#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


struct Coordinate
{
    double longitude;
    double latitude;

    void operator() (double lat, double lng){
        longitude = lng;
        latitude = lat;
    }

    void operator= (Coordinate other){
        longitude = other.longitude;
        latitude = other.latitude;
    }
};

struct City
{
    std::string country;
    std::string name;
    Coordinate coordinates;
    int population;

    City(std::string country_name, std::string city_name, double lat, double lng, int pop){
        name = city_name;
        country = country_name;
        coordinates(lat, lng);
        population = pop;
    }

    bool operator<(City other){
        return name < other.name;
    }
};

struct Country
{
    std::string name;
    std::vector<City> cities;

    Country (std::string country_name){
        name = country_name;
    }

    void add_city(City city){
        bool flag = true;

        for (auto el : cities){
            if (city.name == el.name){
                flag = false;
                break;
            }
        }

        if (flag) cities.push_back(city);
    }

    bool operator<(Country other){
        return name < other.name;
    }
};

int inVector(Country country, std::vector<Country> countries){
    for (int i = 0; i < countries.size(); i++){
        if (countries[i].name == country.name) return i + 1;
    }

    return 0;
}

void fillCountries(std::istream& inFile, std::vector<Country>& countries)
{
    std::string str, word;
    std::vector<std::string> info;
    std::getline(inFile, str);
    while(std::getline(inFile, str)){
        info.clear();

        std::stringstream line(str);
        while (std::getline(line, word, ',')){
            info.push_back(word);
        }

//        std::cout << info[0] << ' ' << info[1] << ' ' << info[2] << ' ' << info[3] << ' ' << info[4] << '\n';

        City city(info[3], info[0], std::stod(info[1]),
                  std::stod(info[2]), std::stoi(info[4]));
        Country country(info[3]);

        if (inVector(country, countries)) {
            countries[inVector(country, countries) - 1].add_city(city);
        }
        else{
            country.add_city(city);
            countries.push_back(country);
        }
    }
}

void printContainer(std::vector<Country> countries){
    for (auto country : countries){
        if (!country.cities.empty()){
            std::cout << country.name << '\n'
                        << country.cities.size() << " cities" << '\n';
            for (auto city : country.cities){
                std::cout << "City name: " << std::left << std::setw(15) << city.name << '\t'
                            << "Coordinates: " << std::setw(10) << city.coordinates.latitude
                            << std::setw(10) << city.coordinates.longitude << '\t'
                            << "Population: " << city.population << '\n';
            }
        }
        else std::cout << "No cities in " << country.name;

        std::cout << "\n\n";
    }
}

int main()
{
    const std::string FILENAME = "/Users/senya/CLionProjects/Plusi dla loxov/week9/data/problem1_cities/cities.csv";
    std::ifstream inputFile;
    inputFile.open(FILENAME);
    if(inputFile)
    {
        std::cout<<"OK\n";
    }

    std::vector<Country> countries;
    fillCountries(inputFile, countries);

    printContainer(countries);
    return 0;
}