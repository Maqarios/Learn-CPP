#include <iostream>
#include "task.h"
#include "task_manager.h"

int main()
{
    TaskManager tm;

    tm.addTask("X", "XXXXXXXXXX", Priority::LOW);
    tm.addTask("Y", "YYYYYYYYYY", Priority::MEDIUM);
    tm.addTask("Z", "ZZZZZZZZZZ", Priority::HIGH);
    tm.displayAll();

    std::cout << "Find by ID(=2):\n  "
              << *tm.findTaskById(2) << "\n";

    tm.removeTask(3);
    std::cout << "Remove & Find by ID(=3):\n  "
              << "Found? " << (tm.findTaskById(3) != nullptr) << "\n";

    bool is_success = tm.updateStatus(1, Status::IN_PROGRESS);
    std::cout << "Update Status(=IN_PROGRESS) & Find by ID(=1):\n  "
              << "  Is success? " << is_success << "\n"
              << "  Task: " << *tm.findTaskById(1) << "\n";

    is_success = tm.updatePriority(2, Priority::LOW);
    std::cout << "Update Priority(=LOW) & Find by ID(=2):\n  "
              << "  Is success? " << is_success << "\n"
              << "  Task: " << *tm.findTaskById(2) << "\n";

    is_success = tm.updatePriority(3, Priority::LOW);
    std::cout << "Update Priority(=LOW) & Find by ID(=3):\n  "
              << "  Is success? " << is_success << "\n";

    return 0;
}