#include <iostream>
#include "student.h"
#include "course.h"

int main()
{
    Student s1 = Student("John Doe", 1);
    s1.addGrade(74);

    Student s2 = Student("Jane Doe", 2);
    s2.addGrade(80);

    Course c = Course("Maths");
    c.addStudent(s1);
    c.addStudent(s2);
    c.displayRoster();

    return 0;
}