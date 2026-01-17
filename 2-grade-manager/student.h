#pragma once

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Student
{
private:
    std::string m_name;
    int m_id;
    std::vector<double> grades;

public:
    Student(std::string name, int id);
    std::string getName() const;
    int getId() const;
    bool addGrade(double grade);
    double getAverage() const;
    double getMinGrade() const;
    double getMaxGrade() const;
};