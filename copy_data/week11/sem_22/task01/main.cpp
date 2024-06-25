/*
Design a logging system in C++ that allows for messages of different severity levels to be
 recorded to a file. Your task involves creating a `Logger` class that supports logging messages
 with varying levels of importance, namely ERROR, WARNING, INFO, and DEBUG. The `Logger` class
 should be implemented as a singleton to ensure that only one instance can exist throughout the application.
 It must provide a method to set the logging level and another to log messages, which includes the message's timestamp,
 its level, and the text. The logger should append messages to a log file, with the ability to
 specify the file's name when accessing the logger instance for the first time. Additionally,
 the logger should ignore messages that are below the current logging level.

Implement a demonstration of using this logging system by creating a simple function that performs an
 operation (e.g., summing two integers) and logs messages at different levels based on the operation's
 progression. The main function should adjust the logging level to demonstrate filtering based on the
 level and ensure that the logging output includes relevant timestamps and message levels.
*/

#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Logger {
public:
    enum class Level {
    ERROR = 0,
    WARNING,
    INFO,
    DEBUG,
    };

private:
    std::ofstream logFile;
    Level currentLevel;

    explicit Logger(const std::string &filename, Level level = Level::INFO) : currentLevel(level){
        logFile.open(filename);
    }

public:
    Logger(const Logger &) = delete;
    Logger &operator=(const Logger &) = delete;
    ~Logger() = default;

    static Logger &getInstance(const std::string &filename = "logfile.txt") {
        static Logger instance(filename);
        return instance;
    }

    void setLevel(Level level) {
        currentLevel = level;
    }

    void log(const std::string &message, Level level = Level::INFO) {
        if (!logFile.is_open()){
            std::cout << "Aboba ne rabotaet\n";
            return;
        }
        else std::cout << "Zae... vse norm\n";

        time_t rawtime;
        time(&rawtime);
        auto time = std::put_time(std::localtime(&rawtime), "%Y-%m-%d %X");
        setLevel(level);

        logFile << time << ", " << levelToString(currentLevel) << ", " << message << '\n';
    }

private:
    static std::string levelToString(Level level) {
        switch (level) {
            case Level::DEBUG:
                return "DEBUG";
            case Level::ERROR:
                return "ERROR";
            case Level::WARNING:
                return "WARNING";
            case Level::INFO:
                return "INFO";
        }
    }
};

auto &logger = Logger::getInstance("/Users/senya/CLionProjects/Plusi dla loxov/week11/sem_22/task01/logfile.txt");

int sum(int a, int b) {
    logger.log("Зашли в метод sum.", Logger::Level::DEBUG);
    int res = a + b;
    logger.log("Суммируем числа " + std::to_string(a) + " "
                + std::to_string(b) + "res = " + std::to_string(res),
                Logger::Level::INFO);
    return a + b;
}

int main() {
    logger.setLevel(Logger::Level::DEBUG);
    sum(10, 20);

    time_t rawtime;
    time(&rawtime);
    std::cout << "Текущая дата/время : "
              << std::put_time(std::localtime(&rawtime), "%Y-%m-%d %X");

    return 0;
}
