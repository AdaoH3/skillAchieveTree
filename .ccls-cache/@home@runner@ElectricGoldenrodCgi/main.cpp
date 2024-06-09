#include <iostream>
#include <vector>
#include "SkillTree.h"        
#include "Task.h"

SkillTree* skillTree;
void printAvailable();

int main() {
    // Seeding Random
    srand(time(NULL));

    // Projects
    Task codexScopeDIY("Codex Scope DIY Manual", "projects");
    Task dragonKimWorkshops("Dragon Kim Workshops", "projects");
    Task schoolClubImprovements("School Club Improvements", "projects");
    Task codexScopeDemo("CodexScope Demo Product", "projects", {codexScopeDIY});
    Task clockCountdown("Clock Countdown", "projects", {codexScopeDIY, codexScopeDemo});

    // Skills
    Task githubGit("Github and Git", "skills");
    Task linuxSkill("Linux", "skills");
    Task unity("Unity Basics", "skills");
    Task graphics("GraphicsLibrary", "skills");
    Task electronJs("LearnElectron", "skills");
    Task serialTransmit("Serial Transmit", "skills");

    Task serialTAndR("Serial Transmit and Receive", "skills", {serialTransmit, unity});
    Task bashScript("Bash Scripting", "skills", {linuxSkill, githubGit});
    Task raspberryPi("Raspberry Pi", "skills", {linuxSkill});
    Task webPortfolio("Web Portfolio", "skills", {electronJs});

    // Studies
    Task satMath("SAT Math", "studies");
    Task satReading( "SAT Reading", "studies");
    Task amcMath("AMC Math", "studies");
    Task driverTest("DriverTest", "studies");

    // Necessarry 
    Task chestWorkout("Chest Workout", "workout");
    Task tricepWorkout("Tricep Workout", "workout");
    Task sAndBWorkout("Shoulder and Back Workout", "workout");
    Task lAndFWorkout("Leg and Forearm Workout", "workout");

    std::vector<Task> tasks = {
        codexScopeDIY, dragonKimWorkshops, schoolClubImprovements, 
        codexScopeDemo, clockCountdown, githubGit, linuxSkill, unity,
        graphics, electronJs, serialTransmit, serialTAndR, bashScript, 
        raspberryPi, webPortfolio, satMath, satReading, amcMath, driverTest,
        chestWorkout, tricepWorkout, sAndBWorkout, lAndFWorkout
    };

    skillTree = new SkillTree(tasks);

    

    /*
    while(true)
    {
            std::string input = "0";
            while (true) {

                if(input.compare("1") != 0)
                {
                    printAvailable();
                }
                std::cout << "Enter Number: " << std::endl;
                std::cout << "[1] Roll" << std::endl;
                std::cout << "[2] Mark Task as Done" << std::endl;
                std::cout << "[3] Exit" << std::endl;
                std::getline(std::cin, input);

                if (input == "1") {
                    std::cout << "\033[2J\033[1;1H";
                    printAvailable();
                    skillTree->generalPull(1, 2, 1); // Adjust the parameters as needed
                    std::cout << "---" << std::endl;
                } else if (input == "2") {

                    std::cout << "Enter Task Name: " << std::endl;
                    std::getline(std::cin, input);
                    skillTree->markDone(input);
                   // std::cout << "\033[2J\033[1;1H";
                } else if (input == "3") {
                    break;
                } else {
                    std::cout << "Invalid input." << std::endl;
                }
            }

            return 0;
    }
*/

}


void printAvailable()
{
    std::vector<Task> availableTasks = skillTree->getAvailable();
    std::cout << "Available tasks: " << skillTree->formatTasks(availableTasks) << 
    std::endl;
    std::cout << "---" << std::endl;
}
