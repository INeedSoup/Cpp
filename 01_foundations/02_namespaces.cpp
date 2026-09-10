#include <iostream>

// namespace : provides a solution for preventing name conflicts in large projects. Each entity needs a unique name. 
//             A namespace allows for identically named entities as long as the namespaces are different.

namespace first
{
    int x = 1;
}

namespace second
{
    int x = 2;
}

int main()
{
    int x = 0;

    std::cout << x << "\n"; // local version of x

    std::cout << first::x << "\n"; // :: this is the scope resolution operator

    std::cout << second::x << "\n";

    // using namespaces we can have entities with same names

    // using namespace first; with this command we set first as the namespace so now we dont have specify explicitly which namespace to use for the whole scope where this is written
    std::cout << x;

    return 0;
}