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
