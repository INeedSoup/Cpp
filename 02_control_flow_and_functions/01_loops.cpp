/* Learn: loops repeat work; choose while for an unknown count, do/while for at least one run, and for for counted work.
Why: Repetition avoids copying the same statements.
Watch out: update the value tested by the condition, or the loop may never end.
Try next: Change the nested loop to print a multiplication table. */
#include <iostream>

int main()
{
    int positiveNumber = -1;
    while (positiveNumber < 0)
    {
        std::cout << "Enter a non-negative number: ";
        std::cin >> positiveNumber;
    }

    int choice{};
    do
    {
        std::cout << "Enter 1 to continue or 0 to stop: ";
        std::cin >> choice;
    } while (choice != 0 && choice != 1);

    for (int number = 1; number <= 5; ++number)
    {
        if (number == 3)
            continue; // Skip this iteration only.
        std::cout << number << ' ';
    }
    std::cout << "\n";

    for (int row = 1; row <= 3; ++row)
    {
        for (int column = 1; column <= 4; ++column)
            std::cout << "(" << row << ", " << column << ") ";
        std::cout << '\n';
    }
}
