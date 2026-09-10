#include <iostream>

int main()
{
    int age{};
    std::cout << "Enter your age: ";
    std::cin >> age;

    // Put narrower or exceptional cases before broad cases.
    if (age < 0)
        std::cout << "Age cannot be negative.\n";
    else if (age >= 100)
        std::cout << "Please contact the support desk.\n";
    else if (age >= 18)
        std::cout << "Adult account selected.\n";
    else
        std::cout << "Minor account selected.\n";

    char grade{};
    std::cout << "Enter a letter grade (A-F): ";
    std::cin >> grade;
    switch (grade)
    {
    case 'A': case 'B': std::cout << "Great work.\n"; break;
    case 'C': std::cout << "Passed.\n"; break;
    case 'D': case 'F': std::cout << "Needs improvement.\n"; break;
    default: std::cout << "That is not a recognised uppercase grade.\n";
    }

    const int marks = 75;
    std::cout << (marks >= 60 ? "Pass\n" : "Fail\n");
}
