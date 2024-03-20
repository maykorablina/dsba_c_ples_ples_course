#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>


struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads;
    using Workload = std::map<std::string, int>::value_type;

    Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads);

    int getTotalLoad() const;
};

struct Worker {
    std::string name;
    std::string login;
    int maxLoad;

    Worker(const std::string& name, const std::string& login, int maxLoad);

    // might be needed for task 5
    bool isOverworked(const std::vector<Task>& tasks) const;
};

// task 1
Task::Task(const std::string& t, const std::string& d, const std::map<std::string, int>& wl)
{
    text = t;
    date = d;
    workloads = wl;
}

Worker::Worker(const std::string& n, const std::string& l, int mL)
{
    name = n;
    login = l;
    maxLoad = mL;
}


// task 2
int Task::getTotalLoad() const
{
    int sum = 0;

    for (auto i : workloads) sum += i.second;

    return sum;
}

// task 3
bool sorter(Task task_1, Task task_2){
    if (task_1.getTotalLoad() != task_2.getTotalLoad()){
        return task_1.getTotalLoad() < task_2.getTotalLoad();
    }
    else if (task_1.date != task_2.date){
        return task_1.date < task_2.date;
    }
    return task_1.text < task_2.text;
}

void sortTasks(std::vector<Task>& tasks)
{
    std::sort(tasks.begin(), tasks.end(), sorter);
}

// task 4
int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker)
{
    int sum = 0;

    for (auto task : allTasks){
        for (auto work : task.workloads){
            if (worker.login == work.first) sum += work.second;
        }
    }

    return sum;
}

void addTask(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    int total_load, maximum;

    for (auto el : newTask.workloads){
        for (auto man : workers){
            if (el.first == man.login){
                total_load = getWorkerLoad(tasks, man) + el.second;
                maximum = man.maxLoad;
                break;
            }
        }

        if (total_load > maximum)
            throw std::runtime_error("Overworked");
    }
    tasks.push_back(newTask);
}

// task 6
bool sortir(std::pair<std::string, int> task_1, std::pair<std::string, int> task_2){
    return task_1.first < task_2.first;
}

void addTaskVerbose(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    int total;
    std::pair<std::string, int> pair;
    tasks.push_back(newTask);
    std::vector<std::pair<std::string, int>> overworked;

    for (auto worker : workers){
        total = getWorkerLoad(tasks, worker);
        pair.first = worker.login, pair.second = total - worker.maxLoad;

        if (total > worker.maxLoad) {
            overworked.push_back(pair);
        }
    }

    if (overworked.size() > 0){
        std::sort(overworked.begin(), overworked.end(), sortir);
        std::string str = "Overworked: ";
        for (int i = 0; i < overworked.size(); i++){
            str += overworked[i].first + " by " + std::to_string(overworked[i].second);

            if (i < overworked.size() - 1) str += ", ";
        }

        throw std::runtime_error(str);
    }
}
