#include <iostream>
#include <regex>
#include "student.h"
#include "course.h"

bool addStudentMenu(Course &c);
bool addGradeToStudentMenu(Course &c);

int main()
{
    std::string course_name;
    std::cout << "Enter course name: ";
    std::cin >> course_name;
    Course c = Course(course_name);

    bool running = true;
    while (running)
    {
        char choice;
        std::cout << "Choose (1. Add student 2. Add grade to student 3. Display roster 4. Save 5. Load 6. Exit): ";
        std::cin >> choice;

        bool is_success;
        switch (choice)
        {
        case '1':
            is_success = addStudentMenu(c);
            if (is_success)
                std::cout << "Operation Passed!\n";
            else
                std::cout << "Operation Failed!\n";
            break;
        case '2':
            is_success = addGradeToStudentMenu(c);
            if (is_success)
                std::cout << "Operation Passed!\n";
            else
                std::cout << "Operation Failed!\n";
            break;
        case '3':
            c.displayRoster();
            break;
        case '4':
            try
            {
                c.saveToFile(course_name + " - Course Data.txt");
            }
            catch (char const *msg)
            {
                std::cout << "ERROR: " << msg << "!\n";
            }
            break;
        case '5':
            try
            {
                c.loadFromFile(course_name + " - Course Data.txt");
            }
            catch (char const *msg)
            {
                std::cout << "ERROR: " << msg << "!\n";
            }
            break;
        case '6':
            running = false;
            break;
        default:
            std::cout << "Wrong choice! ";
            continue;
        }
    }

    return 0;
}

bool addStudentMenu(Course &c)
{
    const std::regex name_pattern("^[a-zA-Z\\s]+$");
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;
    if (name.empty())
    {
        std::cout << "WARNING: Name cannot be empty!\n";
        return false;
    }
    if (!std::regex_match(name, name_pattern))
    {
        std::cout << "WARNING: Name can only have characters and/or white spaces!\n";
        return false;
    }

    const std::regex id_pattern("^[0-9]+$");
    std::string id_str;
    std::cout << "Enter ID: ";
    std::cin >> id_str;
    if (id_str.empty())
    {
        std::cout << "WARNING: ID cannot be empty!\n";
        return false;
    }
    if (!std::regex_match(id_str, id_pattern))
    {
        std::cout << "WARNING: ID can only have numbers!\n";
        return false;
    }

    int id = std::stoi(id_str);
    Student *s_ptr = c.getStudentById(id);
    if (s_ptr)
    {
        std::cout << "WARNING: Another student with same ID exists!\n";
        return false;
    }

    Student s = Student(name, id);
    c.addStudent(s);
    return true;
}

bool addGradeToStudentMenu(Course &c)
{
    const std::regex id_pattern("^[0-9]+$");
    std::string id_str;
    std::cout << "Enter Student ID: ";
    std::cin >> id_str;
    if (id_str.empty())
    {
        std::cout << "WARNING: ID cannot be empty!\n";
        return false;
    }
    if (!std::regex_match(id_str, id_pattern))
    {
        std::cout << "WARNING: ID can only have numbers!\n";
        return false;
    }

    int id = std::stoi(id_str);
    Student *s_ptr = c.getStudentById(id);

    if (!s_ptr)
    {
        std::cout << "Warning: No student with ID " << id << " found!\n";
        return false;
    }

    const std::regex grade_pattern("^[0-9]*\\.?[0-9]+$");
    std::string grade_str;
    std::cout << "Enter Grade: ";
    std::cin >> grade_str;
    if (grade_str.empty())
    {
        std::cout << "WARNING: Grade cannot be empty!\n";
        return false;
    }
    if (!std::regex_match(grade_str, grade_pattern))
    {
        std::cout << "WARNING: Grade can only have numbers and/or .!\n";
        return false;
    }

    double grade = std::stod(grade_str);

    return s_ptr->addGrade(grade);
}