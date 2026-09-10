#include <algorithm>
#include <cmath>
#include <iostream>

int main()
{
    const int totalQuestions = 10;
    const int correctAnswers = 8;

    // Integer division discards the fractional part: 8 / 10 is 0.
    std::cout << "Integer division: " << correctAnswers / totalQuestions << '\n';
    const double percentage = static_cast<double>(correctAnswers) / totalQuestions * 100.0;
    std::cout << "Percentage: " << percentage << "%\n";
    std::cout << "17 % 5 = " << 17 % 5 << '\n';

    const double x = 3.7;
    std::cout << "floor: " << std::floor(x) << ", round: " << std::round(x)
              << ", sqrt(16): " << std::sqrt(16.0) << '\n';
    std::cout << "Larger value: " << std::max(4.0, 7.5) << '\n';
}
