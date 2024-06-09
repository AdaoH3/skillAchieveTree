#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <vector>
#include "Task.h"
#include <fstream>

class SkillTree {
public:
    SkillTree(std::vector<Task> tasks);

    //Available List
    bool checkAvailable(Task taskVar);
    void filterAvailable();

    //Formatting List
    std::string formatTasks(const std::vector<Task>& unformatted) const;
    void printAvailable();

    //Pulling Functions
    Task pullType(std::string type);
    std::vector<Task> pullMultType(int num, std::string type);
    std::string generalPull(int projects, int skills, int studies);

    //Mark Done
    void markDone(std::string taskName);

    //File Functions
    void saveState(const std::string& filename);
    void loadState(const std::string& filename);
    void resetState(const std::string& filename);

private:
    std::vector<Task> tasks;
    std::vector<Task> available; 
    std::string lastRemovedType;
};

#endif
