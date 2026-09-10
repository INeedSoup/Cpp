#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> values{7, 2, 4, 2, 9, 1};
    std::ranges::sort(values);

    auto firstLarge = std::ranges::find_if(values, [](int value) { return value > 5; });
    const int sum = std::accumulate(values.begin(), values.end(), 0);

    // erase-remove is the standard way to remove matching vector values.
    values.erase(std::remove_if(values.begin(), values.end(),
                                [](int value) { return value % 2 == 0; }),
                 values.end());

    std::cout << "First value > 5: " << *firstLarge << "\nSum before removal: " << sum << "\nOdds: ";
    for (int value : values)
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}
