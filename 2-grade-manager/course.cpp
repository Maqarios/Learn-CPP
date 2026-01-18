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

Student *Course::getStudentById(int id)
{
    for (Student &s : students)
    {
        if (s.getId() == id)
            return &s;
    }
    return nullptr;
}

void Course::displayRoster() const
{
    for (long unsigned int i = 0; i < students.size(); i++)
    {
        std::cout << "Student   : " << (i + 1) << "\n";
        std::cout << "  Name    : " << students[i].getName() << "\n";
        std::cout << "  ID      : " << students[i].getId() << "\n";

        std::cout << "  Grades  : ";
        for (double grade : students[i].getGrades())
            std::cout << grade << " ";
        std::cout << "\n";

        std::cout << "  MIN GRD : " << students[i].getMinGrade() << "\n";
        std::cout << "  MAX GRD : " << students[i].getMaxGrade() << "\n";
        std::cout << "  AVG GRD : " << students[i].getAverage() << "\n";
    }
}

void Course::saveToFile(const std::string &filename) const
{
    std::ofstream file(filename);
    if (!file.is_open())
        throw "file cannot be opened";

    for (long unsigned int i = 0; i < students.size(); i++)
    {
        file << students[i].toString() << "\n";
        if (!file)
            throw "file cannot be written to";
    }

    file.close();
}

void Course::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    std::string line;

    if (!file.is_open())
        throw "file cannot be opened";

    while (std::getline(file, line))
    {
        Student s = Student();
        s.parseString(line);
        addStudent(s);
    }

    file.close();
}