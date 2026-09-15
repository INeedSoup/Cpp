/* Learn: enum class creates a small, type-safe set of named choices.
Why: named states communicate meaning more clearly than unexplained integers.
Watch out: switch should handle every meaningful value, including a default when appropriate.
Try next: Add a function that prints every Day value. */
#include <iostream>

enum class Day
{
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday
};

int main()
{
    const Day today = Day::saturday;
    switch (today)
    {
    case Day::saturday:
    case Day::sunday:
        std::cout << "Weekend\n";
        break;
    default:
        std::cout << "Weekday\n";
        break;
    }
    // enum class avoids leaking names such as monday into the surrounding scope.
}
