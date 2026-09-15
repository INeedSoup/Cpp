/*
Learn: One normalised choice can select the correct conversion formula.
Why: Accepting both c and C makes an interactive program friendlier.
Use: Convert between two fixed units selected by the user.
Watch out: Be clear whether the requested unit is the input unit or the output unit.
Try next: Add Kelvin as a third unit.
*/
#include <cctype>
#include <iostream>

int main()
{
    char targetUnit{};
    double temperature{};
    std::cout << "Convert to (C)elsius or (F)ahrenheit: ";
    std::cin >> targetUnit;
    targetUnit = static_cast<char>(std::toupper(static_cast<unsigned char>(targetUnit)));

    if (targetUnit == 'F')
    {
        std::cout << "Temperature in Celsius: ";
        std::cin >> temperature;
        std::cout << "Temperature: " << (temperature * 9.0 / 5.0 + 32.0) << " F\n";
    }
    else if (targetUnit == 'C')
    {
        std::cout << "Temperature in Fahrenheit: ";
        std::cin >> temperature;
        std::cout << "Temperature: " << ((temperature - 32.0) * 5.0 / 9.0) << " C\n";
    }
    else
        std::cerr << "Choose C or F.\n";
}
