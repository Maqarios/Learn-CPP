#include <iostream>
#include "task.h"
#include "task_manager.h"

int main()
{
    TaskManager tm;

    tm.addTask("X", "XXXXXXXXXX", Priority::LOW);
    tm.addTask("X", "XXXXXXXXXX", Priority::MEDIUM);
    tm.addTask("X", "XXXXXXXXXX", Priority::HIGH);
    tm.displayAll();

    std::cout << "Find by ID(=2):\n  "
              << *tm.findTaskById(2) << "\n";

    return 0;
}