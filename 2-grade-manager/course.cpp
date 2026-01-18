#include "course.h"
#include <iostream>
#include <fstream>
#include <string>

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

void Course::saveToFile(const std::string &filename) const
{
    std::ofstream file(filename);
    for (long unsigned int i = 0; i < students.size(); i++)
    {
        file << students[i].toString() << "\n";
    }
    file.close();
}

void Course::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line))
    {
        Student s = Student(line);
        addStudent(s);
    }
}