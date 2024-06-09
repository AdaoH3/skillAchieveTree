#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <vector>
#include "Task.h"

class Skill {
public:
    Skill(std::string name, std::vector<Task> tasks);

private:
    std::string name;
    std::vector<Task> tasks;
};

#endif
