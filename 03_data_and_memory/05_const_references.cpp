/* Learn: const T& borrows an existing object without copying or changing it.
Why: it is efficient and documents read-only intent for potentially large objects.
Watch out: a reference must always refer to a live object.
Try next: Pass a vector by const reference after completing Stage 5. */
#include <iostream>
#include <string>

void printInfo(const std::string& name, int age)
{
    // The reference avoids copying a potentially large string; const prevents modification.
    std::cout << name << " is " << age << " years old.\n";
}

int main()
{
    const std::string name = "Aman";
    printInfo(name, 21);
}
