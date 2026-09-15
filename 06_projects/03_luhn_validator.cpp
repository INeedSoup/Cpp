/* Learn: the Luhn algorithm processes digits from right to left and combines validation rules.
Why: checksum algorithms catch many typing mistakes without storing external data.
Watch out: passing Luhn does not prove that a card account exists or is authorised.
Try next: Also accept '-' separators, then reject all other punctuation. */
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

bool isValidLuhn(std::string number)
{
    number.erase(std::remove(number.begin(), number.end(), ' '), number.end());
    if (number.size() < 13 || number.size() > 19 ||
        !std::all_of(number.begin(), number.end(), [](unsigned char character) { return std::isdigit(character); }))
    {
        return false;
    }

    int sum = 0;
    bool doubleDigit = false;
    for (auto iterator = number.rbegin(); iterator != number.rend(); ++iterator)
    {
        int digit = *iterator - '0';
        if (doubleDigit)
        {
            digit *= 2;
            if (digit > 9)
                digit -= 9;
        }
        sum += digit;
        doubleDigit = !doubleDigit;
    }
    return sum % 10 == 0;
}

int main()
{
    std::string number;
    std::cout << "Enter a card number (spaces are allowed): ";
    std::getline(std::cin, number);
    std::cout << (isValidLuhn(number) ? "Passes the Luhn checksum.\n" : "Invalid checksum or format.\n");
    // Luhn validates a checksum only; it does not prove an account exists or is safe to use.
}
