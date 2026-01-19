#include <iostream>
#include "task.h"

int main()
{
    Task t = Task(1, "X", "XXXXXXXXXX", Status::TODO, Priority::LOW);
    std::cout << "Create:\n  " << t.toString() << "\n";

    t.setId(2);
    t.setTitle("Y");
    t.setDescription("YYYYYYYYYY");
    t.setStatus(Status::IN_PROGRESS);
    t.setPriority(Priority::MEDIUM);
    std::cout << "Update 1:\n  " << t.toString() << "\n";

    t.setId(3);
    t.setTitle("Z");
    t.setDescription("ZZZZZZZZZZ");
    t.setStatus(Status::DONE);
    t.setPriority(Priority::HIGH);
    std::cout << "Update 2:\n  " << t.toString() << "\n";

    return 0;
}