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

bool Student::addGrade(double grade)
{
    if (grade > 100 || grade < 0)
        return false;

    grades.push_back(grade);
    return true;
}

double Student::getAverage() const
{
    return std::accumulate(grades.begin(), grades.end(), 0.0) / grades.size();
}

double Student::getMinGrade() const
{
    return *std::min_element(grades.begin(), grades.end());
}

double Student::getMaxGrade() const
{
    return *std::max_element(grades.begin(), grades.end());
}