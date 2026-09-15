/*
Learn: A failed input stream must be repaired before it can read again.
Why: Typing text when an int is expected sets a failure flag and leaves bad characters waiting.
Use: Validate all user input before using it in a calculation or decision.
Watch out: clear() fixes the failure flag; ignore() removes the bad characters. You need both.
Try next: Reuse this pattern to accept a score from 0 to 100.
*/
#include <iostream>
#include <limits>

int main()
{
    int age{};
    std::cout << "Enter your age: ";
    while (!(std::cin >> age) || age < 0 || age > 130)
    {
        std::cout << "Please enter a whole number from 0 to 130: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Recorded age: " << age << '\n';
}
