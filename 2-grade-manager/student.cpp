#include "student.h"

Student::Student(std::string name, int id)
{
    m_name = name;
    m_id = id;
}

std::string Student::getName()
{
    return m_name;
}

int Student::getId()
{
    return m_id;
}