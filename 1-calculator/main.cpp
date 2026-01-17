#include <iostream>
#include "calculator.h"

#define RESULTS_SIZE 5

int main()
{
    int results_idx = 0;
    double results[RESULTS_SIZE] = {};

    bool running = true;
    while (running)
    {
        char choice;
        std::cout << "Choose (1. Calculate 2. History 3. Exit): ";
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            try
            {
                double result = calculator();
                results[results_idx++ % RESULTS_SIZE] = result;
            }
            catch (char const *msg)
            {
                std::cout << "ERROR: " << msg << "!\n";
            }
            break;
        case '2':
            if (results_idx <= RESULTS_SIZE)
                for (int idx = 0; idx < results_idx; idx++)
                    std::cout << (idx + 1) << ". " << results[idx] << "\n";
            else
                for (int idx = 0; idx < RESULTS_SIZE; idx++)
                    std::cout << (idx + 1) << ". " << results[(idx + results_idx) % RESULTS_SIZE] << "\n";
            break;
        case '3':
            running = false;
            break;
        default:
            std::cout << "Wrong choice! ";
            continue;
        }
    }

    return 0;
}