#include "student.h"

Student::Student(std::string name, int id)
{
    m_name = name;
    m_id = id;
}

std::string Student::getName() const
{
    return m_name;
}

int Student::getId() const
{
    return m_id;
}

void Student::addGrade(double grade)
{
    grades.push_back(grade);
}

double Student::getAverage() const
{
    double result = 0;
    for (long unsigned int i = 0; i < grades.size(); i++)
        result += grades[i];
    result /= grades.size();

    return result;
}