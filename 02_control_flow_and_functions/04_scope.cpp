/* Learn: scope determines where a name is visible; an inner declaration can hide an outer one.
Why: narrow scope prevents unrelated code from changing or confusing a value.
Use: declare variables as close as possible to their first use.
Watch out: globals are accessible everywhere, so they make dependencies harder to see and test.
Try next: Remove the global value and pass it as a parameter instead. */
#include <iostream>

const int legacyGlobalLimit = 100; // Demonstration only; prefer a local constant or parameter.

void printLimit(int limit)
{
    std::cout << "Parameter limit: " << limit << '\n';
}

int main()
{
    const int localLimit = 10;
    printLimit(localLimit);
    std::cout << "Local limit: " << localLimit << '\n';
    std::cout << "Global limit: " << legacyGlobalLimit << '\n';
    {
        const int localLimit = 5; // This name exists only in this nested block.
        std::cout << "Nested limit: " << localLimit << '\n';
    }
}
