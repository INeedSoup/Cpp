#include <iostream>
#include <stdexcept>

unsigned long long factorial(unsigned int number)
{
    // Base case: without it, recursion would never stop.
    if (number < 2)
        return 1;
    return number * factorial(number - 1);
}

int main()
{
    constexpr unsigned int value = 10;
    std::cout << value << "! = " << factorial(value) << '\n';
    // 20! still fits in unsigned long long; larger inputs overflow this example's return type.
}
