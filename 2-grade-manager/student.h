#pragma once

#include <string>

class Student
{
private:
    std::string m_name;
    int m_id;

public:
    Student(std::string name, int id);
    std::string getName();
    int getId();
};