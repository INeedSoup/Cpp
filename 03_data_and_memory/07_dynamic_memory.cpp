#include <iostream>
#include <memory>

int main()
{
    // Raw new/delete is shown only to recognise existing code.
    int* legacyNumber = new int{21};
    std::cout << "Raw value: " << *legacyNumber << '\n';
    delete legacyNumber;
    legacyNumber = nullptr; // Makes accidental later use easier to detect.

    // Modern C++ expresses heap ownership with a smart pointer.
    auto grades = std::make_unique<char[]>(3);
    grades[0] = 'A';
    grades[1] = 'B';
    grades[2] = 'A';
    for (int index = 0; index < 3; ++index)
    {
        std::cout << grades[index] << ' ';
    }
    std::cout << "\nNo delete[] is necessary: unique_ptr owns the array.\n";
}
