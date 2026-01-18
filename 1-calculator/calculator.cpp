#include "calculator.h"
#include <iostream>

double calculator()
{
    double a, b;
    std::cout << "Enter first number: ";
    std::cin >> a;
    std::cout << "Enter second number: ";
    std::cin >> b;

    char op;
    std::cout << "Enter operator (+, -, *, /): ";
    std::cin >> op;

    double result;
    if (op == '+')
    {
        result = a + b;
        std::cout << a << " + " << b << " = " << result << "\n";
    }
    else if (op == '-')
    {
        result = a - b;
        std::cout << a << " - " << b << " = " << result << "\n";
    }
    else if (op == '*')
    {
        result = a * b;
        std::cout << a << " * " << b << " = " << result << "\n";
    }
    else if (op == '/')
    {
        if (b == 0)
            throw "division by zero";

        result = a / b;
        std::cout << a << " / " << b << " = " << result << "\n";
    }
    else
    {
        throw "Invalid operator!";
    }

    return result;
}