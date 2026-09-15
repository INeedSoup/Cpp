/*
Learn: if/else chooses a path; switch chooses from fixed discrete values.
Why: Programs respond differently when rules or user choices differ.
Use: Use if for ranges and combined conditions; use switch for a small set of exact cases.
Watch out: Order matters in an if/else-if chain because the first true condition wins.
Try next: Add a distinction to the grade message for an A.
*/
#include <iostream>

int main()
{
    int age{};
    std::cout << "Enter your age: ";
    std::cin >> age;

    if (age < 0)
        std::cout << "Age cannot be negative.\n";
    else if (age >= 100)
        std::cout << "Please contact the support desk.\n";
    else if (age >= 18 && age < 100)
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
    std::cout << (marks >= 60 ? "Pass\n" : "Fail\n"); // A ternary expression chooses one value.
}
