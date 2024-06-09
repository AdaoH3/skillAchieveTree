#include "Task.h"
#include <iostream>

Task::Task(std::string name, std::string type, const std::vector<Task>& preReqs)
: name(name), type(type), preReqs(preReqs), isDone(false), pullNum(0) {}


Task::Task(std::string name, std::string type)
    : name(name), type(type), isDone(false), pullNum(0) {}

std::string Task::getName() const {
    return name;
}

std::string Task::getType() const {
    return type;
}

std::vector<Task> Task::getPreReq() const
{
    if(preReqs.empty())
    {
        return {}; 
    }

    return preReqs;
}

void Task::addPullNum() {
    pullNum++;
    //std::cout << name << " Pull Num: " << pullNum << std::endl;
}

int Task::getPullNum() const {
    return pullNum;
}

void Task::setPullNum(int num)
{
    pullNum = num;
}

void Task::markDone() {
    isDone = true; 
}

bool Task::checkDone() const {
    return isDone;
}

