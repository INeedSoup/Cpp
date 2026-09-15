/* Learn: a function template lets the compiler create versions of the same algorithm for compatible types.
Why: generic code avoids duplicate int, double, and string implementations.
Watch out: the selected type must support every operation used by the template.
Try next: Write a template that returns the smaller of two values. */
#include <iostream>
#include <string>

template <typename T>
const T& largerOf(const T& first, const T& second)
{
    return first < second ? second : first;
}

int main()
{
    std::cout << largerOf(7, 12) << '\n';
    std::cout << largerOf(2.5, 1.8) << '\n';
    std::cout << largerOf(std::string{"apple"}, std::string{"pear"}) << '\n';
    // A template is compiled for each type used here, provided that type supports <.
}
