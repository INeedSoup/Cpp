/*
Learn: using creates an alias for an existing type.
Why: A meaningful alias can show what a number represents.
Use: Name a domain concept such as UserId; it can make APIs easier to read.
Watch out: An alias is not a new type, so UserId and int can still be mixed.
Try next: Create an alias for a percentage stored as double.
*/
#include <iostream>
#include <string>

using UserId = int;
using DisplayName = std::string;

int main()
{
    const UserId userId = 42;
    const DisplayName name = "Aman";
    std::cout << name << " has id " << userId << '\n';
}
