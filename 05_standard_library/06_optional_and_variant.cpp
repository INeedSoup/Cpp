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
