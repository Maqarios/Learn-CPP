#include "course.h"
#include <iostream>

Course::Course(std::string name)
{
    m_name = name;
}

void Course::addStudent(const Student &student)
{
    students.push_back(student);
}

void Course::displayRoster() const
{
    std::cout << "Name: " << m_name << "\n";

    for (long unsigned int i = 0; i < students.size(); i++)
    {
        std::cout << "Student   : " << (i + 1) << "\n";
        std::cout << "  Name    : " << students[i].getName() << "\n";
        std::cout << "  ID      : " << students[i].getId() << "\n";
        std::cout << "  AVG GRD : " << students[i].getAverage() << "\n";
    }
}