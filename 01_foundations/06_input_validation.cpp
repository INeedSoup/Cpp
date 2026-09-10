#include <iostream>
#include <limits>

int main()
{
    int age{};

    std::cout << "Enter your age: ";
    while (!(std::cin >> age) || age < 0 || age > 130)
    {
        std::cout << "Please enter a whole number from 0 to 130: ";
        std::cin.clear(); // Clear the stream's failure state.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Recorded age: " << age << '\n';
}
