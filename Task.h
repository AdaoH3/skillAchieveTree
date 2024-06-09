#ifndef TASK_H
#define TASK_H

#include <string>
#include <vector>

class Task {
public:
    Task(std::string name, std::string type, const std::vector<Task>& preReqs);
    Task(std::string name, std::string type);

    //Information String
    std::string getType() const;
    std::string getName() const;
    std::vector<Task> getPreReq() const;
    
    //Number Info
    int getPullNum() const;
    void addPullNum();
    void setPullNum(int num);

    void markDone();
    bool checkDone() const;
    

private:
    std::string name;
    std::string type;
    std::vector<Task> preReqs;

    bool isDone;
    int pullNum;
};

#endif /* TASK_H */
