#pragma once

#include <string>
#include <vector>

class Student
{
private:
    std::string m_name;
    int m_id;
    std::vector<double> grades;

public:
    Student();
    Student(std::string name, int id);
    std::string getName() const;
    int getId() const;
    std::vector<double> getGrades() const;
    bool addGrade(double grade);
    double getAverage() const;
    double getMinGrade() const;
    double getMaxGrade() const;
    std::string toString() const;
    void parseString(std::string input);
};