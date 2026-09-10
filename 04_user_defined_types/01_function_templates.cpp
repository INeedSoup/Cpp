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
