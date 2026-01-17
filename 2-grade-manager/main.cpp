#include <iostream>
#include "student.h"

int main()
{
    Student s = Student("John Doe", 1);
    s.addGrade(87.0);
    s.addGrade(96.0);
    s.addGrade(74.0);
    std::cout << "Name: " << s.getName() << "\n";
    std::cout << "ID: " << s.getId() << "\n";
    std::cout << "Average Grade: " << s.getAverage() << "\n";

    return 0;
}