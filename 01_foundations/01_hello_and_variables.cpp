/*
Learn: A program starts in main(), and variables give values a type and a name.
Why: Types tell the compiler how to store a value and which operations make sense.
Use: Choose the smallest clear type that represents your data.
Watch out: int stores whole numbers only; use double when a fractional result matters.
Try next: Change the radius and predict the final line before running the program.
*/
#include <iostream>
#include <string>

int main()
{
    std::cout << "Hello, C++!\n";

    const int wholeNumber = 42;
    const double price = 19.99;
    const char grade = 'A';
    const bool isLearning = true;
    const std::string name = "Aman";
    constexpr double pi = 3.141592653589793;

    std::cout << name << " has grade " << grade << ".\n"
              << "Integer: " << wholeNumber << ", decimal: " << price
              << ", learning: " << std::boolalpha << isLearning << '\n'
              << "Circle circumference with radius 2: " << 2 * pi * 2 << '\n';
}
