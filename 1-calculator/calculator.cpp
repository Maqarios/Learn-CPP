#include <iostream>

void calculator();

int main()
{
    bool running = true;
    while (running)
    {
        char choice;
        std::cout << "Choose (1. Calculate 2. Exit): ";
        std::cin >> choice;
        switch (choice)
        {
        case '1':
            calculator();
            break;
        case '2':
            running = false;
            break;
        default:
            std::cout << "Wrong choice! ";
            continue;
        }
    }

    return 0;
}

void calculator()
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
        try
        {

            if (b == 0)
                throw "division by zero";

            result = a / b;
            std::cout << a << " / " << b << " = " << result << "\n";
        }
        catch (char const *msg)
        {
            std::cout << "ERROR: " << msg << "!\n";
        }
    }
    else
    {
        std::cout << "Invalud operator!\n";
    }
}