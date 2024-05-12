#include <iostream>
#include <set>
#include "map"
#include <vector>
#include <fstream>
#include <sstream>

//     Main task - to implement the function fillCountries to put countries into a container]
// (vector<Country> or map<std::string, Country>).

//     Intermediate steps:
//     1. Define operator< for both Cities and Countries based on their names.
//     2. Read cities as pairs <City, name of the country>.
//     3. Use the name of the country to find if there is such country in the container.
//     4. Add a country to the container or a city to an existing country.


struct Coordinate
{
private:
    double longitude;
    double latitude;
public:
    Coordinate(double lat, double lon) : latitude(lat), longitude(lon) {}
    double Latitude() const {return latitude;}
    double Longitude() const{return longitude;}
    std::string GetText() const {
        return "(" + std::to_string(latitude) + ", " + std::to_string(longitude) + ")";
    }
};

struct City
{
private:
    std::string name;
    Coordinate coords;
//    std::string country;
    int population;
public:
    City(const std::string cityName, const Coordinate cityCoords, int cityPopulation)
            : name(cityName), coords(cityCoords), population(cityPopulation) {

    }
    bool operator<(const City& other) const {
        return name < other.name;
    }
    bool operator==(const City& other) const {
        return name == other.name;
    }
    const std::string& getName() const {
        return name;
    }
    const Coordinate& getCoords() const {
        return coords;
    }
//    const std::string& getCountry() const {
//        return country;
//    }
    int getPopulation() const {
        return population;
    }
    friend std::ostream& operator<<(std::ostream& os, const City& city) {
        os << "Name: " << city.name << '\n';
        os << "Coords: " << city.coords.GetText() << '\n';
        os << "Population: " << city.population << '\n';
//        os << "Country: " << city.country << '\n';
//        os << "Country: " << city.country << '\n';
        return os;
    }

};

struct Country
{
private:
    std::string name;
    std::vector<City> data;
public:
    Country(const std::string cityName, std::vector<City> d): name(cityName), data(d) {}
    bool operator<(const Country& other) const {
        return name < other.name;
    }
    const std::string& getName() const {
        return name;
    }
    void AddCity(const City& city){
        bool flag = true;
        for (auto c: data) {
            if (c == city) flag = false;
        }
        if (flag) data.push_back(city);
    }

    friend std::ostream& operator<<(std::ostream& os, const Country& city) {
        os << "Name: " << city.name << '\n';
        os << "Cities: ";
        if (city.data.empty()) os << "no cities" << '\n';
        else {
            for (int i = 0; i < city.data.size(); i++) {
                if (i == city.data.size() - 1) {
                    os << city.data[i].getName() << '\n';
                }
                else {
                    os << city.data[i].getName() << ", ";
                }
            }
        }
        return os;
    }
};




bool check_country(std::string name, std::vector<Country> countries) {
    for (auto c: countries){
        if (c.getName() == name) {
            return true;
        }
    }
    return false;
}

void findCountry(std::string name, std::vector<Country> countries) {
    bool flag = false;
    for (auto c: countries) {
        if (c.getName() == name) {
            std::cout << c;
        }
    }
}

std::vector<Country> load_data(std::ifstream& inputFile) {
    std::string line;
    std::getline(inputFile, line);
    std::string piece;
    std::vector<std::string> temp;
    std::map<std::string, std::vector<City>> cd;
    std::vector<Country> ans;
    while (std::getline(inputFile, line)) {
        std::stringstream s(line);
        while (std::getline(s, piece, ',')) {
            temp.push_back(piece);
        }
        std::vector<City> temp2;
        Coordinate c(std::stod(temp[1]), std::stod(temp[2]));
        City sity(temp[0], c, std::stoi(temp[4]));
        temp2.push_back(sity);
        if (cd.find(temp[3]) == cd.end()) {
            cd[temp[3]] = temp2;
        }
        else {
            cd[temp[3]].push_back(sity);
        }
        temp.clear();
        temp2.clear();
    }
    for (auto a : cd) {
        Country cc(a.first, a.second);
        ans.push_back(cc);
    }
    return ans;
}


int main()
{
    std::vector<Country> countries;
    const std::string FILENAME = "/Users/mayakorablina/Yandex.Disk.localized/CodingProjects/cpp_course/2023_2024_2nd_sem/week9/18_sem/data/problem1_cities/cities.csv";
    std::ifstream inputFile(FILENAME);
    std::string line;
    if(inputFile.is_open())
    {
        std::vector<Country> data(load_data(inputFile));
        std::cout << "OK!" << '\n';
        for (auto c: data) {
            std::cout << c;
        }
    }



    return 0;
}
