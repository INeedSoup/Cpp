/*
Learn: Arithmetic combines values; a cast changes how a value is treated in an expression.
Why: The type of an expression determines whether its fractional part is preserved.
Use: Cast before division when you need a decimal result.
Watch out: Do not cast merely to silence a warning—understand the conversion first.
Try next: Change correctAnswers to 9 and compare integer versus decimal division.
*/
#include <algorithm>
#include <cmath>
#include <iostream>

int main()
{
    const int totalQuestions = 10;
    const int correctAnswers = 8;

    std::cout << "Integer division: " << correctAnswers / totalQuestions << '\n';
    const double percentage = static_cast<double>(correctAnswers) / totalQuestions * 100.0;
    std::cout << "Percentage: " << percentage << "%\n";
    std::cout << "17 % 5 = " << 17 % 5 << " (the remainder)\n";

    const double x = 3.7;
    std::cout << "floor: " << std::floor(x) << ", round: " << std::round(x)
              << ", sqrt(16): " << std::sqrt(16.0) << '\n';
    std::cout << "Larger value: " << std::max(4.0, 7.5) << '\n';
}
