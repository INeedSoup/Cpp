/* Learn: optional represents a value that may be absent; variant holds exactly one of listed types.
Why: these types make ordinary alternatives explicit in the function's return type.
Use: optional for an expected “not found”; variant for a fixed set of possible result types.
Watch out: check an optional before dereferencing it; do not use exceptions for routine absence.
Try next: Parse an invalid string and print a helpful message when optional is empty. */
#include <exception>
#include <iostream>
#include <optional>
#include <string>
#include <variant>

std::optional<int> parseSmallPositive(const std::string& text)
{
    try
    {
        const int value = std::stoi(text);
        return value > 0 && value <= 100 ? std::optional{value} : std::nullopt;
    }
    catch (const std::exception&)
    {
        return std::nullopt;
    }
}

int main()
{
    if (const auto number = parseSmallPositive("24"))
    {
        std::cout << "Parsed: " << *number << '\n';
    }

    std::variant<int, std::string> response = "pending";
    std::visit([](const auto& value) { std::cout << "Response: " << value << '\n'; }, response);
}
