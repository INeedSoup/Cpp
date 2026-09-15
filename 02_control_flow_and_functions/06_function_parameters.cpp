/* Learn: value parameters copy, references alias, and const references borrow without modification.
Why: the parameter form documents whether a function changes caller-owned data.
Watch out: never return a reference to a local object.
Try next: Add a function that changes a string only when it is non-empty. */
#include <iostream>
#include <string>

void addSuffixByValue(std::string text)
{
    text += "!"; // Only the local copy changes.
}

void addSuffixByReference(std::string& text)
{
    text += "!"; // The caller's string changes.
}

void printLabel(const std::string& text)
{
    // const reference avoids a copy and promises not to modify text.
    std::cout << "Label: " << text << '\n';
}

int main()
{
    std::string message = "Hello";
    addSuffixByValue(message);
    printLabel(message); // Still "Hello".

    addSuffixByReference(message);
    printLabel(message); // Now "Hello!".
}
