#include "student.h"
#include <numeric>
#include <algorithm>
#include <sstream>
#include <iterator>

Student::Student(std::string line)
{
    parseString(line);
}

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

std::vector<double> Student::getGrades() const
{
    std::vector<double> output;
    std::copy(grades.begin(), grades.end(), std::back_inserter(output));

    return output;
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

std::string Student::toString() const
{
    std::string output = m_name + "," + std::to_string(m_id) + ",";
    if (!grades.empty())
    {
        std::ostringstream oss;
        std::copy(grades.begin(), grades.end() - 1, std::ostream_iterator<double>(oss, ";"));
        oss << grades.back();

        output += oss.str();
    }

    return output;
}

void Student::parseString(std::string line)
{
    std::stringstream ss(line);
    std::string temp;

    int i = 0;
    for (char c; ss.get(c);)
    {
        temp += c;

        if (ss.peek() == ',' || ss.peek() == ';' || ss.peek() == -1)
        {
            ss.ignore();
            switch (i++)
            {
            case 0:
                m_name = temp;
                break;
            case 1:
                m_id = std::stoi(temp);
                break;
            default:
                addGrade(std::stoi(temp));
                break;
            }

            temp.clear();
        }
    }
}