#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

class Task {
public:
    Task(std::string name, std::string type, const std::vector<Task>& preReqs);
    Task(std::string name, std::string type);

    void markDone();
    bool checkAvailable() const;
    bool checkDone() const;
    std::string getType() const;
    int getPullNum() const;
    void addPullNum();
    std::string getName() const;

    // Updated function declaration
    void addDependent(const Task* dependent);
    void updateAvailability();

private:
    std::string name;
    std::string type;
    std::vector<Task> preReqs;
    bool isDone;
    int pullNum;
    std::vector<const Task*> dependents; // Changed to store const pointers
};

#endif /* TASK_H */
