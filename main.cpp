#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class TaskManager {
public:
    TaskManager() {
        loadTasks();
    }

    void loadTasks() {
        std::ifstream file("tasks.txt");
        std::string task;
        while (std::getline(file, task)) {
            tasks.push_back(task);
        }
        file.close();
    }

    void saveTasks() {
        std::ofstream file("tasks.txt");
        for (const std::string& task : tasks) {
            file << task << std::endl;
        }
        file.close();
    }

    void addTask(const std::string& task) {
        tasks.push_back(task);
        saveTasks();
    }

    void deleteTask(int taskNumber) {
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            saveTasks();
        }
    }

    void displayTasks() {
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << std::endl;
        }
    }

    void start() {
        std::string action;
        while (true) {
            std::cout << "\nTodo List App\n" << std::endl;
            displayTasks();
            std::cout << "\nWhat would you like to do? (add/delete/quit): ";
            std::cin >> action;

            if (action == "add") {
                std::cin.ignore();
                std::string newTask;
                std::cout << "Enter a new task: ";
                std::getline(std::cin, newTask);
                addTask(newTask);
            } else if (action == "delete") {
                int taskNumber;
                std::cout << "Enter the task number to delete: ";
                std::cin >> taskNumber;
                deleteTask(taskNumber);
            } else if (action == "quit") {
                break;
            } else {
                std::cout << "Invalid action. Please choose add, delete, or quit." << std::endl;
            }
        }
    }

private:
    std::vector<std::string> tasks;
};

int main() {
    TaskManager taskManager;
    taskManager.start();
    return 0;
}
