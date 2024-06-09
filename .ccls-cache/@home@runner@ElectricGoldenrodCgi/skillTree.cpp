#include "SkillTree.h"
#include <stdlib.h>
#include <time.h> 
#include <iostream>
#include <climits>
#include <algorithm>

SkillTree::SkillTree(std::vector<Task> tasks)
    : tasks(tasks) {}

/*
    Pre: Available Task List
    Post: Returns a Task of the Specified Type
*/
Task SkillTree::pullType(std::string type) {
    std::vector<Task*> typeList;
    int smallestPull = INT_MAX; // Initialize to a large value

    // Get list of specific type
    for (auto& task : tasks) {
        if (task.getType().compare(type) == 0 && task.checkAvailable() && !task.checkDone()) {
            typeList.push_back(&task);
        }
    }

    // Find smallest pull number
    for (auto* task : typeList) {
        if (task->getPullNum() < smallestPull) {
            smallestPull = task->getPullNum();
        }
    }

    // Get list of tasks with smallest pull number
    std::vector<Task*> smallPullTypeList;
    for (auto* task : typeList) {
       if (task->getPullNum() == smallestPull) {
           smallPullTypeList.push_back(task);
       }
    }

    // If more than one task with smallest pull number, pick randomly
    int randomPick = rand() % smallPullTypeList.size();
    smallPullTypeList[randomPick]->addPullNum(); // Increment pull number
    return *smallPullTypeList[randomPick];
}

/*
Pre: Task vector list
Post: Returns available tasks in a vector of tasks
*/
std::vector<Task> SkillTree::getAvailable()
{
    std::vector<Task> availableList;

    for(const auto& task : tasks)
    {
        if(task.checkAvailable() && !task.checkDone())
        {
            availableList.push_back(task);
        }
    }

    return availableList;
}

/*
Pre: Task Name
Post: Task gets marked done
*/
void SkillTree::markDone(std::string taskName)
{
    for(auto& task : tasks)
    {
        if(task.getName().compare(taskName) == 0)  
        {
            task.markDone();
            return; 
        }
    }
}

/*
Pre: Number of tasks of specific type
Post: Vector of tasks of a specific type to do
*/
std::vector<Task> SkillTree::pullMultType(int num, std::string type)
{
    std::vector<Task> multTasks; 
    std::vector<Task*> availableTasks;

    // Get list of specific type
    for (auto& task : tasks) {
        if (task.getType().compare(type) == 0 && task.checkAvailable() && !task.checkDone()) {
            availableTasks.push_back(&task);
        }
    }

    for(int i = 0; i < num && !availableTasks.empty(); i++)
    {
        // Find smallest pull number
        int smallestPull = INT_MAX;
        for (auto* task : availableTasks) {
            if (task->getPullNum() < smallestPull) {
                smallestPull = task->getPullNum();
            }
        }

        // Get list of tasks with smallest pull number
        std::vector<Task*> smallPullTypeList;
        for (auto* task : availableTasks) {
            if (task->getPullNum() == smallestPull) {
                smallPullTypeList.push_back(task);
            }
        }

        // Pick a random task among those with the smallest pull number
        int randomPick = rand() % smallPullTypeList.size();
        Task* selectedTask = smallPullTypeList[randomPick];
        selectedTask->addPullNum(); // Increment pull number
        multTasks.push_back(*selectedTask);

        // Remove the selected task from available tasks
        availableTasks.erase(std::remove(availableTasks.begin(), availableTasks.end(), selectedTask), availableTasks.end());
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
