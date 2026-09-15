/*
Learn: A namespace groups names and the :: operator selects a name from one.
Why: Large programs and libraries can define the same short name without colliding.
Use: Put related library code in a namespace; write std::cout to show its origin.
Watch out: Avoid using namespace std; in headers or large scopes because it imports many names.
Try next: Add a third namespace with another value named count.
*/
#include <iostream>

namespace classroom
{
    inline int count = 24;
}

namespace library
{
    inline int count = 1'200;
}

int main()
{
    const int count = 3; // This local name hides names with the same spelling outside main.
    std::cout << "Local count: " << count << '\n';
    std::cout << "Classroom count: " << classroom::count << '\n';
    std::cout << "Library count: " << library::count << '\n';
}
