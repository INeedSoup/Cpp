#include <iostream>
#include <string>

int main()
{
    // Every complete C++ program starts execution in main().
    std::cout << "Hello, C++!\n";

    int wholeNumber = 42;
    double price = 19.99;
    char grade = 'A';
    bool isLearning = true;
    std::string name = "Aman";
    constexpr double pi = 3.141592653589793;

    std::cout << name << " has grade " << grade << ".\n"
              << "Integer: " << wholeNumber << ", decimal: " << price << ", learning: " << isLearning << '\n'
              << "Circle circumference with radius 2: " << 2 * pi * 2 << '\n';
}
