#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

class Task {
public:
    Task(std::string name, std::string type, const std::vector<Task>& preReqs);
    void markDone();
    bool checkAvailable();
    bool checkDone();

private:
    std::string name;
    std::string type;
    std::vector<Task> preReqs;
    bool isDone;
};

#endif
