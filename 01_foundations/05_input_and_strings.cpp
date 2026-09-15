/*
Learn: >> reads a formatted token; getline reads an entire line, including spaces.
Why: Names and sentences commonly contain spaces, while ages do not.
Use: Use getline for human-readable text and >> for simple numeric/token input.
Watch out: Formatted input leaves a newline behind; std::ws consumes it before getline.
Try next: Ask for a favourite food containing a space.
*/
#include <iostream>
#include <string>

int main()
{
    int age{};
    std::string fullName;

    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Full name: ";
    std::getline(std::cin >> std::ws, fullName);
    std::cout << "Hello, " << fullName << ". You are " << age << ".\n";
}
