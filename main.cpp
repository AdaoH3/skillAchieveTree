#include <iostream>
#include <vector>
#include "SkillTree.h"        
#include "Task.h"

SkillTree* skillTree;

int main() {
    // Seeding Random
    srand(time(NULL));

    //Initializing variables
    int projectPull;
    int skillPull;
    int studyPull;
    
    // Projects
    Task codexScopeDIY("Codex Scope DIY Manual", "projects");
    Task dragonKimWorkshops("Dragon Kim Workshops", "projects");
    Task schoolClubImprovements("School Club Improvements", "projects");
    Task codexScopeDemo("Codex Scope Demo Product", "projects", {codexScopeDIY});
    Task clockCountdown("Clock Countdown", "projects", {codexScopeDIY, codexScopeDemo});

    // Skills
    Task githubGit("Github And Git", "skills");
    Task linuxSkill("Linux", "skills");
    Task unity("Unity Basics", "skills");
    Task graphics("Graphics Library", "skills");
    Task electronJs("Learn Electron", "skills");
    Task serialTransmit("Serial Transmit", "skills");

    Task serialTAndR("Serial Transmit And Receive", "skills", {serialTransmit, unity});
    Task bashScript("Bash Scripting", "skills", {linuxSkill, githubGit});
    Task raspberryPi("Raspberry Pi", "skills", {linuxSkill});
    Task webPortfolio("Web Portfolio", "skills", {electronJs});

    // Studies
    Task satMath("SAT Math", "studies");
    Task satReading( "SAT Reading", "studies");
    Task amcMath("AMC Math", "studies");
    Task driverTest("Driver Test", "studies");

    // Necessarry 
    Task chestWorkout("Chest Workout", "workout");
    Task tricepWorkout("Tricep Workout", "workout");
    Task sAndBWorkout("Shoulder And Back Workout", "workout");
    Task lAndFWorkout("Leg And Forearm Workout", "workout");

    std::vector<Task> tasks = {
        codexScopeDIY, dragonKimWorkshops, schoolClubImprovements, 
        codexScopeDemo, clockCountdown, githubGit, linuxSkill, unity,
        graphics, electronJs, serialTransmit, serialTAndR, bashScript, 
        raspberryPi, webPortfolio, satMath, satReading, amcMath, driverTest,
        chestWorkout, tricepWorkout, sAndBWorkout, lAndFWorkout
    };

    //Pre condition: No task will have the same name
    skillTree = new SkillTree(tasks);
    //skillTree->printAvailable();
    
    skillTree->loadState("skilltree_state.txt");
    skillTree->filterAvailable();
    // Your program logic...

    // Save the state of the skill tree to a file before exiting
 

    ///*
    while(true)
    {
        
            std::string input = "0";
            int inputNum;
            while (true) {

  
                if(input.compare("1") != 0)
                {

                }
                std::cout << "Enter Number: " << std::endl;
                std::cout << "[1] Roll" << std::endl;
                std::cout << "[2] Change Inputs" << std::endl;
                std::cout << "[3] Mark Task as Done" << std::endl;
                std::cout << "[4] Reset Skill Tree" << std::endl;
                std::cout << "[5] Exit" << std::endl;
                std::getline(std::cin, input);

                if (input == "1") {
                    std::cout << "\033[2J\033[1;1H";
                    skillTree->generalPull(projectPull, skillPull, studyPull); // Adjust the parameters as needed
                    std::cout << "---" << std::endl;
                
                } else if (input == "2") {
                    // Prompt the user for input
                    std::cout << "Enter Project Num: ";
                    std::cin >> inputNum;
                    projectPull = inputNum;
                    std::cout << "Enter Skill Num: ";
                    std::cin >> inputNum;
                    skillPull = inputNum;
                    std::cout << "Enter Study Num: ";
                    std::cin >> inputNum;
                    studyPull = inputNum;

                    std::getline(std::cin, input);
                    
                    std::cout << "\033[2J\033[1;1H";
                    
                } else if (input == "3") {

                    std::cout << "Enter Task Name: " << std::endl;
                    std::getline(std::cin, input);
                    skillTree->markDone(input);
                   // std::cout << "\033[2J\033[1;1H";
                } else if (input == "4") {
                    skillTree->resetState("skilltree_state.txt");
                    break;
                } else if (input == "5") {
                    skillTree->saveState("skilltree_state.txt");
                    break;
                } else {
                    std::cout << "Invalid input." << std::endl;
                }
            }

            return 0;
    }
    //*/
}
