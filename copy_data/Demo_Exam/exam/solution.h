#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>
#include <stdexcept>

//========================================
//==========< Problem 1 [3pts] >==========

class Teacher
{
public:
    Teacher(std::string  name)
        : _name(std::move(name))
    {
    }

    virtual ~Teacher() {}

    const std::string& getName() const { return _name; }
    virtual double calcWages() const = 0;
    virtual Teacher* cloneMe() const = 0;

protected:
    std::string _name;
};

class AssociateTeacher : public Teacher
{
private:
    int _bonus;

public:
    static const int BASE_SALARY = 1500;

    AssociateTeacher(const std::string& name, int bonus): Teacher(name), _bonus(bonus){}

    int getBonus() const{
        return _bonus;
    }

    double calcWages() const override {
        return BASE_SALARY + _bonus;
    }

    Teacher* cloneMe() const override{
        return new AssociateTeacher(_name, _bonus);
    }
};

class InvitedTeacher : public Teacher
{
private:
    int _stuGroups;

public:
    static const int GROUP_TAX = 2000;

    InvitedTeacher(const std::string& name, int stuGroups): Teacher(name), _stuGroups(stuGroups){}

    int getStuGroups() const {
        return _stuGroups;
    }

    double calcWages() const override {
        return GROUP_TAX * _stuGroups;
    }

    Teacher* cloneMe() const override{
        return new InvitedTeacher(_name, _stuGroups);
    }
};

//========================================
//==========< Problem 2 [3pts] >==========

class TArray {
public:
    TArray()= default;

    TArray(const TArray& other){
        if (!_arr.empty()) _arr.clear();

        for (int i = 0; i < other.getSize(); i++){
            _arr.push_back(other[i]->cloneMe());
        }
    }

    TArray& operator=(const TArray& other){
        if (!_arr.empty()) _arr.clear();

        for (int i = 0; i < other.getSize(); i++){
            _arr.push_back(other[i]->cloneMe());
        }

        return *this;
    }

    size_t getSize() const
    {
        return _arr.size();
    }

    AssociateTeacher* addAssociateTeacher(const std::string& name, int bonus){
        auto buf = new AssociateTeacher(name, bonus);
        _arr.push_back(buf);
        return buf;
    }

    InvitedTeacher* addInvitedTeacher(const std::string& name, int stuGroups){
        auto buf = new InvitedTeacher(name, stuGroups);
        _arr.push_back(buf);
        return buf;
    }

    Teacher* operator[](size_t index) const{
        if(index >= (_arr.size()))
        {
            throw std::out_of_range("Index out of range");
        }
        return _arr[index];

    }

    ~TArray(){
        for (auto el: _arr) {
            delete el;
        }
    }
protected:
    std::vector<Teacher*> _arr;
};

std::ostream& operator << (std::ostream& os, const TArray& tArr)
{
    for (int i = 0; i < tArr.getSize(); i++){
        os << tArr[i]->getName() << ',' << tArr[i]->calcWages() << '\n';
    }

    return os;
}

//========================================
//==========< Problem 3 [2pts] >==========
std::pair<int,int> totalWagesOfTopTeachers(const TArray& tArr, int minGroups, int minBonus)
{
    std::pair<int, int> result;

    for (int i = 0; i < tArr.getSize(); i++){
        if(dynamic_cast<InvitedTeacher*>(tArr[i])){
            auto* invT = dynamic_cast<InvitedTeacher*>(tArr[i]);
            if (invT->getStuGroups() >= minGroups){
                result.first += invT->calcWages();
            }
        }
        else if (dynamic_cast<AssociateTeacher*>(tArr[i])) {
            auto* assT = dynamic_cast<AssociateTeacher*>(tArr[i]);
            if (assT->getBonus() >= minBonus){
                result.second += assT->calcWages();
            }
        }
    }

    return result;
}

#endif
