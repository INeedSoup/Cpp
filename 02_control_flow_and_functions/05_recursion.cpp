/* Learn: recursion calls a function with a smaller problem until a base case stops it.
Why: some structures and algorithms are naturally defined in smaller versions of themselves.
Watch out: each call uses stack space; use a loop when it is simpler.
Try next: Write a recursive sum from 1 to n. */
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
