#include "SkillTree.h"
#include <stdlib.h>
#include <time.h> 
#include <iostream>
#include <climits>
#include <algorithm>

SkillTree::SkillTree(std::vector<Task> tasks)
    : tasks(tasks) {
    // Initialize available vector
    filterAvailable();
    std::cout << "Available tasks initialized: " << available.size() << std::endl;
}



Task SkillTree::pullType(std::string type) {
    std::vector<Task>& typeList = available; // Use reference to avoid copying
    
    if (typeList.empty()) {
        throw std::out_of_range("No available tasks of the specified type");
    }

    int smallestPull = INT_MAX;

    // Find smallest pull number
    for (Task& task : typeList) {
        if (task.getType() == type && task.getPullNum() < smallestPull) {
            smallestPull = task.getPullNum();
        }
    }

    // Get list of tasks with smallest pull number
    std::vector<Task*> smallPullTypeList;
    for (Task& task : typeList) {
        if (task.getType() == type && task.getPullNum() == smallestPull) {
            smallPullTypeList.push_back(&task);
        }
    }

    // If more than one task with smallest pull number, pick randomly
    int randomPick = rand() % smallPullTypeList.size();
    Task& selectedTask = *smallPullTypeList[randomPick]; // Use reference
    selectedTask.addPullNum(); // Increment pull number
    return selectedTask;
}




void SkillTree::filterAvailable()
{
    int smallestPull = INT_MAX;

    // Find the smallest pull number from the currently available tasks
    if (!available.empty()) {
        for (const Task& task : available) {
            smallestPull = std::min(smallestPull, task.getPullNum());
        }
    } else {
        smallestPull = 0;  // If there are no available tasks, start with 0
    }

    // Add new tasks to the available vector
    for (const auto& task : tasks) {
        if (checkAvailable(task)) {
            // Check if the task is already available
            bool taskExists = std::find_if(available.begin(), available.end(), [&](const Task& t) {
                return t.getName() == task.getName();
            }) != available.end();

            if (!taskExists) {
                Task newTask = task;
                newTask.setPullNum(smallestPull);
                available.push_back(newTask);
            }
        }
    }
}



bool SkillTree::checkAvailable(Task taskVar)
{
    //Checks if no pre-reqs and if the task isn't done
    if (taskVar.getPreReq().empty() && !taskVar.checkDone()) {
        return true;
    }
    //If there is pre-reqs and the task is done, remove
    else if(taskVar.checkDone())
    {
        return false; 
    }

    //If the task is not done and there is pre-reqs, check if the pre-reqs are done
    for (const auto& req : taskVar.getPreReq()) {
        bool found = false;  

        for (const auto& task : tasks) {
            if (req.getName() == task.getName() && task.checkDone()) {
                found = true;
                break;  
            }
        }

        if (!found) {
            return false;
        }
    }
    
    return true;
}



void SkillTree::markDone(std::string taskName)
{
    for(auto& task : tasks)
    {
        if(task.getName().compare(taskName) == 0)  
        {
            task.markDone();
            lastRemovedType = task.getType();
            available.erase(std::remove_if(available.begin(), available.end(),
                            [&taskName](const Task& t) {
                                return t.getName() == taskName;
                            }),
            available.end());
            
            filterAvailable();
            return; 
        }
    }

}

std::vector<Task> SkillTree::pullMultType(int num, std::string type) {
    std::vector<Task> multTasks;

    while (num > 0) {
        try {
            Task selectedTask = pullType(type);
            if (std::find_if(multTasks.begin(), multTasks.end(), [&selectedTask](const Task& t) {
                return t.getName() == selectedTask.getName();
            }) == multTasks.end()) {
                // Task not found in multTasks, add it
                multTasks.push_back(selectedTask);
                --num;
            }
        } catch (const std::out_of_range&) {
            // Handle the case where pullType cannot find a task of the specified type
            break;
        }
    }

    return multTasks;
}


std::string SkillTree::formatTasks(const std::vector<Task>& unformatted) const {
    std::string formatted = "";

    for (const Task& task: unformatted) {
        formatted += "[" + task.getName() + "] ";
    }

    return formatted;
}

std::string SkillTree::generalPull(int projects, int skills, int studies)
{
    std::cout << "Projects: " << formatTasks(pullMultType(projects, "projects")) << std::endl;
    std::cout << "Skills: " << formatTasks(pullMultType(skills, "skills")) << std::endl;
    std::cout << "Studies: " << formatTasks(pullMultType(studies, "studies")) << std::endl;
    std::cout << "Workouts: " << formatTasks(pullMultType(1, "workout")) << std::endl;

    return "";
}

void SkillTree::printAvailable()
{
    std::cout << formatTasks(available) << std::endl;
}