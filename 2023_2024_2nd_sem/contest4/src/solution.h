#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads;
    using Workload = std::map<std::string, int>::value_type;

    Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads);
    int getTotalLoad() const;
};

// task 1
Task::Task(const std::string& t, const std::string& d, const std::map<std::string, int>& w)
{
    text = t;
    date = d;
    workloads = w;
}


struct Worker {
    std::string name;
    std::string login;
    int maxLoad;

    Worker(const std::string& name, const std::string& login, int maxLoad);

    // might be needed for task 5
    bool isOverworked(const std::vector<Task>& tasks) const;
};

// task 1
Worker::Worker(const std::string& n, const std::string& l, int ml)
{
    name = n;
    login = l;
    maxLoad = ml;
}


// task 2
int Task::getTotalLoad() const
{
    int sum = 0;
    for (auto i : workloads) {
        sum += i.second;
    }
    return sum;
}

// task 3

bool sort_function(Task t1, Task t2) {
    if (t1.getTotalLoad() == t2.getTotalLoad()) {
        if (t1.date == t2.date) {
            return t1.text < t2.text;
        }
        else return t1.date < t2.date;
    }
    else {
        return t1.getTotalLoad() < t2.getTotalLoad();
    }
}

void sortTasks(std::vector<Task>& tasks)
{
    std::sort(tasks.begin(), tasks.end(), sort_function);
}

// task 4
int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker)
{
    int sum = 0;
    for (Task t : allTasks) {
        for (auto w : t.workloads) {
            if (w.first == worker.login) {
                sum += w.second;
            }
        }
    }
    return sum;
}

// task 5
void addTask(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    int total_workload = 0;
    int max_workload = 0;
    for (auto w : newTask.workloads) {
        for(auto slave : workers) {
            if (w.first == slave.login) {
                total_workload = getWorkerLoad(tasks, slave) + w.second;
                max_workload = slave.maxLoad;
                break;
            }
        }
        if (total_workload <= max_workload) {
            tasks.push_back(newTask);
        } else {
            throw std::runtime_error("Overworked");
        }
    }
}

// task 6

void addTaskVerbose(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    std::vector<std::string> died_slaves;
    std::string rip;
    tasks.push_back(newTask);
    bool flag = false;
    for (auto slave : workers) {
        int slave_load = getWorkerLoad(tasks, slave);
        if (slave_load > slave.maxLoad) {
            flag = true;
            rip = slave.login + " by " + std::to_string(slave_load - slave.maxLoad);
            died_slaves.push_back(rip);
        }
    }
    std::sort(died_slaves.begin(), died_slaves.end());
    std::string ans = "Overworked: ";
    for (int i = 0; i < died_slaves.size();i++){
        if (i == died_slaves.size() - 1) {
            ans += died_slaves[i];
        }
        else ans += died_slaves[i] + ", ";
    }

    if (flag) throw std::runtime_error(ans);

}
