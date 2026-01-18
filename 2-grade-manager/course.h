#pragma once

#include "student.h"
#include <string>
#include <vector>

class Course
{
private:
    std::string m_name;
    std::vector<Student> students;

public:
    Course(std::string name);
    Student *getStudentById(int id);
    void addStudent(const Student &student);
    void displayRoster() const;
    void saveToFile(const std::string &filename) const;
    void loadFromFile(const std::string &filename);
};