#include <iostream>
#include "student.h"
#include "course.h"

int main()
{

    Course c = Course("Maths");
    c.loadFromFile("course_data.txt");

    Student s1 = Student("John Doe", 1);
    s1.addGrade(74);
    s1.addGrade(96);
    c.addStudent(s1);

    Student s2 = Student("Jane Doe", 2);
    s2.addGrade(80);
    s2.addGrade(90);
    c.addStudent(s2);

    c.displayRoster();

    c.saveToFile("course_data.txt");

    return 0;
}