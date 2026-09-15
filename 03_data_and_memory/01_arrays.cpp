#include <array>
#include <iostream>
#include <string>

int main()
{
    // A built-in array has a fixed size. std::array is its safer standard-library wrapper.
    std::array<std::string, 3> students{"Asha", "Bala", "Chen"};
    students.at(1) = "Bina"; // at() checks bounds; [] does not.

    for (const std::string& student : students)
    {
        std::cout << student << '\n';
    }

    std::cout << "Number of students: " << students.size() << '\n';
    // See Stage 5 for std::vector when the size must change at runtime.
}
