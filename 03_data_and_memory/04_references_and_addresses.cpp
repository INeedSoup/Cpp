/* Learn: pass-by-value copies an object; a reference parameter aliases the caller's object.
Why: a copy cannot change the caller, while a reference can avoid a copy and intentionally update it.
Use: pass by value for an independent copy; pass by reference when mutation is part of the function's job.
Watch out: use const references for read-only access; swapping can use std::swap in real code.
Try next: Print the address of a single int through a const void pointer. */
#include <iostream>
#include <string>

void changeCopy(std::string text) { text = "changed locally"; }
void swapByReference(std::string& first, std::string& second)
{
    const std::string temporary = first;
    first = second;
    second = temporary;
}

int main()
{
    std::string first = "Kool-Aid";
    std::string second = "Water";
    std::cout << "Address of first: " << static_cast<const void*>(&first) << '\n';

    changeCopy(first);
    std::cout << "After pass-by-value: " << first << '\n';
    swapByReference(first, second);
    std::cout << "After pass-by-reference: " << first << ", " << second << '\n';
}
