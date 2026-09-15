/*
Learn: switch can select an arithmetic operation from a character.
Why: Grouping each operator with its calculation keeps a small menu readable.
Use: One input selects one known action.
Watch out: Division by zero is invalid for floating-point calculations too.
Try next: Add a remainder operator that accepts integers only.
*/
#include <iostream>

int main()
{
    char operation{};
    double left{};
    double right{};
    std::cout << "Enter an expression, for example: 12.5 * 4\n> ";
    if (!(std::cin >> left >> operation >> right))
    {
        std::cerr << "Invalid input.\n";
        return 1;
    }

    switch (operation)
    {
    case '+': std::cout << left + right << '\n'; break;
    case '-': std::cout << left - right << '\n'; break;
    case '*': std::cout << left * right << '\n'; break;
    case '/':
        if (right == 0.0)
        {
            std::cerr << "Division by zero is undefined.\n";
            return 1;
        }
        std::cout << left / right << '\n';
        break;
    default:
        std::cerr << "Supported operations are +, -, *, and /.\n";
        return 1;
    }
}
