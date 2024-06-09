#include "Task.h"
#include <iostream>

Task::Task(std::string name, std::string type, const std::vector<Task>& preReqs)
    : name(name), type(type), preReqs(preReqs), isDone(false), pullNum(0) {}

Task::Task(std::string name, std::string type)
    : name(name), type(type), isDone(false), pullNum(0) {}

void Task::markDone() {
    isDone = true; // Mark the task as done
}


bool Task::checkAvailable() const {
    if (preReqs.empty()) {
        return true;
    }

    for (const auto& preReq : preReqs) {
        if (!preReq.checkDone()) {
            return false;
        }
    }
 
    return true;
}

bool Task::checkDone() const {
    return isDone;
}

std::string Task::getType() const {
    return type;
}

int Task::getPullNum() const {
    return pullNum;
}

void Task::addPullNum() {
    pullNum++;
}

std::string Task::getName() const {
    return name;
}
