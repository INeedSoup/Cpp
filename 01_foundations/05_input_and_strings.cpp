#include <iostream>
#include <string>

int main()
{
    int age{};
    std::string fullName;

    std::cout << "Age: ";
    std::cin >> age;

    // std::ws consumes whitespace left by formatted input before getline reads a whole line.
    std::cout << "Full name: ";
    std::getline(std::cin >> std::ws, fullName);
    std::cout << "Hello, " << fullName << ". You are " << age << ".\n";
}
