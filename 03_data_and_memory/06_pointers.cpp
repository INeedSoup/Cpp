/* Learn: a pointer stores an address and nullptr represents “no object”.
Why: pointers can model optional non-owning access.
Watch out: checking for nullptr does not protect against a dangling pointer.
Try next: Point at an int, change it through the pointer, then print the int. */
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
