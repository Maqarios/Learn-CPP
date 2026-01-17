#include <iostream>
#include "student.h"

int main()
{
    Student s = Student("John Doe", 1);
    std::cout << "Name: " << s.getName() << "\n";
    std::cout << "ID: " << s.getId() << "\n";

    std::cout << "Add -1? " << s.addGrade(-1) << "\n";
    std::cout << "Add 0? " << s.addGrade(0) << "\n";
    std::cout << "Add 74? " << s.addGrade(74) << "\n";
    std::cout << "Add 87? " << s.addGrade(87) << "\n";
    std::cout << "Add 96? " << s.addGrade(96) << "\n";
    std::cout << "Add 100? " << s.addGrade(100) << "\n";
    std::cout << "Add 101? " << s.addGrade(101) << "\n";

    std::cout << "Average Grade: " << s.getAverage() << "\n";
    std::cout << "Minimum Grade: " << s.getMinGrade() << "\n";
    std::cout << "Maximum Grade: " << s.getMaxGrade() << "\n";

    return 0;
}