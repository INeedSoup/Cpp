#include <iostream>
#include <string>

int main()
{
    std::string name = "Aman";
    std::string* namePointer = &name; // Stores an address; it does not own name.

    if (namePointer != nullptr)
    {
        std::cout << "Value: " << *namePointer << "\nAddress: " << static_cast<const void*>(namePointer) << '\n';
    }

    int* optionalNumber = nullptr;
    if (optionalNumber == nullptr)
    {
        std::cout << "No number has been assigned.\n";
    }
    // Never dereference nullptr, a dangling pointer, or an uninitialised pointer.
}
