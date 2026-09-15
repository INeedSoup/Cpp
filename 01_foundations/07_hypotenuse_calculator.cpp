/*
Learn: std::hypot calculates sqrt(a*a + b*b) safely and clearly.
Why: Library functions make a familiar formula easier to read and reduce repeated arithmetic.
Use: Apply it to the two perpendicular sides of a right-angled triangle.
Watch out: A length cannot be negative; reject invalid real-world input.
Try next: Print the result with two decimal places using <iomanip>.
*/
#include <cmath>
#include <iostream>

int main()
{
    double sideA{};
    double sideB{};
    std::cout << "Enter side A: ";
    std::cin >> sideA;
    std::cout << "Enter side B: ";
    std::cin >> sideB;

    if (sideA < 0.0 || sideB < 0.0)
    {
        std::cerr << "Side lengths cannot be negative.\n";
        return 1;
    }
    std::cout << "Hypotenuse: " << std::hypot(sideA, sideB) << '\n';
}
