// User class: The base class from which the
// all other classes are inherited. Includes
// basic information about the user (for example, name).

// Employee class: Derived from User, representing
// employee. Adds a level of access to resources specific
// for staff.

// Manager class: Derived from User, representing a manager.
// Managers have a higher level of access than regular ones
// employees, and can manage department resources.

// Administrator class: Derived class that should inherit
// properties and methods from both Employee and Manager. Administrators
// have the highest level of access allowing them to manage resources
// at all levels.

// Implement a class system using virtual inheritance,
// to solve the problem of diamond-shaped inheritance and correctly
// organize a hierarchy of classes User, Employee, Manager and
//Administrator. Every class must provide a method
// accessResources() demonstrating the user's access level.

#include <iostream>
#include <string>

class User {
protected:
    std::string name;

public:
    User(std::string name) : name(name) {
      std::cout << "User " << name << " was created" << '\n';
    }

    virtual void accessResources() const {
      std::cout << name << " has basic user access" << std::endl;
    }

    ~User() {
      std::cout << "User " << name << " was deleted" << '\n';
    }
};

class Employee: User {
public:
    Employee(std::string name): User(name) {
        std::cout << "Employee " << name << " was created" << '\n';
    }

    void accessResources() const override{
        std::cout << name << " has basic employee access" << std::endl;
    }

    ~Employee() {
        std::cout << "Employee " << name << " was deleted" << '\n';
    }
};

class Manager: User {
public:
    Manager(std::string name): User(name) {
        std::cout << "Manager " << name << " was created" << '\n';
    }

    void accessResources() const override{
        std::cout << name << " has mid employee access" << std::endl;
    }

    ~Manager() {
        std::cout << "Manager " << name << " was deleted" << '\n';
    }
};

class Administrator: Manager, Employee {
protected:
    std::string name;

public:
    Administrator(std::string name): Manager(name), Employee(name), name(name) {
        std::cout << "Administrator " << name << " was created" << '\n';
    }

    void accessResources() const override{
        std::cout << name << " has highest employee access" << std::endl;
    }

    ~Administrator() {
        std::cout << "Administrator " << name << " was deleted" << '\n';
    }
};


int main() {
    User user("Aleko");
    Employee employee("Makarjomba");
    Manager manager("Nihad");
    Administrator administrator("Maya");
    std::cout << '\n';

    user.accessResources();
    employee.accessResources();
    manager.accessResources();
    administrator.accessResources();

    std::cout << '\n';

    return 0;
}
