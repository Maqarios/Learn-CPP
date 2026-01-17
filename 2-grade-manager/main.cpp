#include <iostream>
#include "student.h"

int main()
{
    Student s = Student("John Doe", 1);
    std::cout << "Name: " << s.getName() << "\n";
    std::cout << "ID: " << s.getId() << "\n";

    return 0;
}