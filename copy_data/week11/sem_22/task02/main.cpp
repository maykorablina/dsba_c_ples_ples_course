#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

/*
Develop a flexible logging system that supports logging messages to different outputs: a file, a database,
 and a network. Your task is to design a base `Logger` class with a virtual method for logging messages. Then,
 extend this base class with three specific logger types:

1. **FileLogger** - logs messages to a file. It should append messages to the specified file, opening the file in
 append mode. If the file cannot be opened, the system should report an error.

2. **DatabaseLogger** - simulates logging to a database by outputting a message to the console indicating that the
 logging is being done to a database.

3. **NetworkLogger** - simulates logging to a network location by outputting a message to the console indicating that
 the logging is being done over a network.

To manage the creation of logger objects, implement a `LoggerFactory` class with a method `createLogger` that takes
 an enum value indicating the desired logger type and returns a logger object of that type. The factory should support
 creating objects of types `FileLogger`, `DatabaseLogger`, and `NetworkLogger`.

In the main function, demonstrate the usage of your logging system by creating one logger of each type and logging a
 message to show how each logger type handles the message.

Ensure your implementation:
- Follows the principles of object-oriented design, particularly polymorphism for the logging functionality.
- Manages resources properly, especially file handles in the `FileLogger`.
- Provides meaningful output to the console to indicate where the message is being logged for the `DatabaseLogger`
 and `NetworkLogger`.

This task will test your ability to use polymorphism, design patterns (specifically, the Factory Method), and resource
 management in C++.
 * */

class MainLogger{
public:
    virtual ~MainLogger(){
        std::cout << "Logger was closed" << '\n';
    }

    void logMessage(const std::string& msg) const{
        std::cout << msg << '\n';
    }
};


class FileLogger : public MainLogger{
private:
    std::string filename;
    std::ofstream output;

public:
    void openFile(const std::string& path){
        output.open(path);
        if (!output.is_open()){
            std::cout << "This file can`t be opened" << '\n';
        }
        else filename = path;
    }

    ~FileLogger() override{
        std::cout << "File was closed" << '\n';
    }
};


class DatabaseLogger : public MainLogger{
private:
    std::string filename;

public:
    void openDataBase(const std::string& path){
        if (path == "Aboba"){
            std::cout << "This DataBase can`t be opened" << '\n';
        }
        else filename = path;
    }

    ~DatabaseLogger() override{
        std::cout << "DataBase was closed" << '\n';
    }
};


class NetworkLogger : public MainLogger{
private:
    std::string network;

public:
    void openDataBase(const std::string& path){
        if (path == "Aboba"){
            std::cout << "This Network can`t be opened" << '\n';
        }
        else network = path;
    }

    ~NetworkLogger() override{
        std::cout << "DataBase was closed" << '\n';
    }
};


class LoggerFactory{
private:

public:
    enum LogType{
        FILE,
        DATABASE,
        NETWORK
    };

    static MainLogger* createLogger(LogType type = LogType::FILE){
        switch (type) {
            case FILE:
                return new FileLogger();
            case DATABASE:
                return new DatabaseLogger();
            case NETWORK:
                return new NetworkLogger();
        }
    }
};

int main() {
    auto fileLogger = LoggerFactory::createLogger(LoggerFactory::FILE);
    fileLogger->logMessage("This is a file logging message.");

    auto databaseLogger = LoggerFactory::createLogger(LoggerFactory::DATABASE);
    databaseLogger->logMessage("This is a database logging message.");

    auto networkLogger = LoggerFactory::createLogger(LoggerFactory::NETWORK);
    networkLogger->logMessage("This is a network logging message.");

    delete fileLogger;
    delete databaseLogger;
    delete networkLogger;

    return 0;
}