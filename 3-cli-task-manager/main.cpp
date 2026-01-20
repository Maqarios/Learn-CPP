#include <iostream>
#include "task.h"

int main()
{
    Task t1 = Task(1, "X", "XXXXXXXXXX", Status::TODO, Priority::LOW);
    std::cout << "Create:\n  " << t1 << "\n";

    t1.setId(2);
    t1.setTitle("Y");
    t1.setDescription("YYYYYYYYYY");
    t1.setStatus(Status::IN_PROGRESS);
    t1.setPriority(Priority::MEDIUM);
    std::cout << "Update 1:\n  " << t1 << "\n";

    t1.setId(3);
    t1.setTitle("Z");
    t1.setDescription("ZZZZZZZZZZ");
    t1.setStatus(Status::DONE);
    t1.setPriority(Priority::HIGH);
    std::cout << "Update 2:\n  " << t1 << "\n";

    Task t2 = Task(2, "A", "AAAAAAAAAA", Status::TODO, Priority::MEDIUM);

    std::cout << "T1 == T1?  " << (t1 == t1) << "\n";
    std::cout << "T1 == T2?  " << (t1 == t2) << "\n";

    return 0;
}