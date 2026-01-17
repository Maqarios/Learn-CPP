#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "student.h"

class Course
{
private:
    std::string m_name;
    std::vector<Student> students;

public:
    Course(std::string name);
    void addStudent(const Student &student);
    void displayRoster() const;
};