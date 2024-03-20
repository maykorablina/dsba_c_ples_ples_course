#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>


class FootballTeam{
private:
    std::string name;
    std::string city;
    std::string stadium;
    int points = 0;
    int wins = 0;
    int loses = 0;
    int draws = 0;
    double level;

public:
    FootballTeam(std::string n, std::string c, std::string s, double l): name(n), city(c), stadium(s), level(l){}

    std::string getName(){
        return name;
    }

    std::string getCity(){
        return city;
    }

    std::string getStadium(){
        return stadium;
    }

    void addWin(){
        wins++;
    }

    void addLoss(){
        loses++;
    }

    void addDraw(){
        draws++;
    }

    void setPoints(int p){
        points = p;
    }

    int getPoints(){
        return points;
    }

    double getLevel(){
        return level;
    }
};

class Match{
public:
    int localGoals = 0;
    int visitorGoals = 0;
    FootballTeam& localTeam;
    FootballTeam& visitorTeam;

    Match(FootballTeam& lt, FootballTeam& vt): localTeam(lt), visitorTeam(vt){
        std::uniform_real_distribution<double> rand(-localTeam.getLevel(),visitorTeam.getLevel());
        std::default_random_engine engine;
        int k = std::ceil(std::abs(localTeam.getLevel() - visitorTeam.getLevel())) * 10;
        int totalGoals = std::rand() % k;

        for (int i = 0; i < totalGoals; i++){
            double goal = rand(engine);

            if (goal < 0) localGoals++;
            else visitorGoals++;
        }
    }

    void play(){
        if (localGoals > visitorGoals){
            localTeam.addWin();
            localTeam.setPoints(3);

            visitorTeam.addLoss();
        }
        else if (localGoals < visitorGoals){
            visitorTeam.addWin();
            visitorTeam.setPoints(3);

            localTeam.addLoss();
        }
        else{
            visitorTeam.addDraw();
            visitorTeam.setPoints(1);

            localTeam.addDraw();
            localTeam.setPoints(1);
        }
    }
};

std::ostream& operator<<(std::ostream& out, Match match){
    out << "localTeam: " << std::left << std::setw(25) << match.localTeam.getName() + ' ' + match.localTeam.getCity() << "  " <<
        "visitorTeam: " << std::setw(25) << match.visitorTeam.getName() + ' ' + match.visitorTeam.getCity() << "  " <<
        "stadium: " << std::setw(25) << match.localTeam.getStadium() <<
        "result: " << match.localGoals << '-' << match.visitorGoals << '\n';

    return out;
}

class Tournament{
public:
    std::vector<FootballTeam>& teams;
    int round = 0;

    Tournament(std::vector<FootballTeam>& t): teams(t){}

    void simulateRound(){
        std::cout << "Round " << round << ":\n";
        for (int i = 0; i < teams.size() / 2; i++){
            Match match(teams[i], teams[teams.size() - 1 - i]);
            match.play();
            std::cout << match;
        }

        std::cout << "\n\n";
        round++;
    }

    void switchTeams(){
        teams.insert(teams.begin() + 1, teams.back());
        teams.pop_back();
    }
};

void parseLineTeam(const std::string& line, std::string& name, std::string& city, std::string& stadium, double& level)
{
    size_t posName = line.find(',');
    name = line.substr(0, posName);
    
    size_t posCity = line.find(',', posName + 1);
    city = line.substr(posName + 1, posCity - posName - 1);
    
    size_t posStadium = line.find(',', posCity + 1);
    stadium = line.substr(posCity + 1, posStadium - posCity - 1);
    
    size_t posLevel = line.size() - 1;
    std::string levelString = line.substr(posStadium + 1, posLevel - posStadium);
    std::stringstream ss(levelString);
    ss >> level;
    
}

void loadTeams(std::istream& in, std::vector<FootballTeam>& teams)
{
    std::string buffer;
    std::getline(in, buffer);
    while(std::getline(in, buffer))
    {
        std::string name;
        std::string city;
        std::string stadium;
        double level;
        parseLineTeam(buffer, name, city, stadium, level);
        std::cout << "name = " << name << "\n";
        std::cout << "city = " << city << "\n";
        std::cout << "stadium = " << stadium << "\n";
        std::cout << "level = " << level << "\n\n";

        FootballTeam team(name, city, stadium, level);
        teams.push_back(team);
    }
}

bool sortirovka(FootballTeam a, FootballTeam b){
    if (a.getPoints() != b.getPoints()) return a.getPoints() > b.getPoints();
    else if (a.getCity() != b.getCity()) return a.getCity() > b.getCity();
    return a.getName() > b.getName();
}

int main()
{
    const std::string FILENAME = "/Users/senya/CLionProjects/Plusi dla loxov/week9/data/problem2_matches/football.csv";
    std::ifstream inputFile;
    inputFile.open(FILENAME);
    
    std::vector<FootballTeam> teams;
    loadTeams(inputFile, teams);

    Tournament tournament(teams);
    for (int i = 0; i < teams.size() - 1; i++){
        tournament.simulateRound();
        tournament.switchTeams();
    }

    std::sort(teams.begin(), teams.end(), sortirovka);
    std::cout << "Teams info: \n";
    for (auto team: teams){
        std::cout << "Name: " << std::left << std::setw(18) << team.getName() << "  " <<
                  "City: " << std::setw(18) << team.getCity() << "  " <<
                  "Points: " << std::setw(4) << team.getPoints() << '\n';
    }
    
    return 0;
}
