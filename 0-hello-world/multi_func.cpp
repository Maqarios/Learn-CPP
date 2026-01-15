#include <iostream>

int add(int a, int b);

int main()
{
    int a = 5123;
    int b = 6182;
    int sum = add(a, b);
    std::cout << a << " + " << b << " = " << sum << "\n";

    return 0;
}

int add(int a, int b)
{
    return a + b;
}