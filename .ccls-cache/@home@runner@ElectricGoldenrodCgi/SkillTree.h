#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <vector>
#include "Task.h"

class SkillTree {
public:
    SkillTree(std::vector<Task> tasks);

    std::vector<Task> getAvailable();
    std::string formatTasks(const std::vector<Task>& unformatted) const;

    Task pullType(std::string type);
    std::vector<Task> pullMultType(int num, std::string type);
    std::string generalPull(int projects, int skills, int studies);

    void markDone(std::string taskName);

private:
    std::vector<Task> tasks;
};

#endif
