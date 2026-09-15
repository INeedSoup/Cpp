/* Learn: algorithms operate on a range; a lambda supplies a short, local rule.
Why: standard algorithms communicate intent and are tested more widely than handwritten loops.
Use: sort, search, filter, and combine container data.
Watch out: erase can invalidate iterators, so use an iterator before changing its container.
Try next: Replace remove_if with a lambda that removes values smaller than 5. */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

int main()
{
    std::vector<int> values{7, 2, 4, 2, 9, 1};
    std::ranges::sort(values);

    const auto firstLarge = std::ranges::find_if(values, [](int value) { return value > 5; });
    if (firstLarge != values.end())
        std::cout << "First value > 5: " << *firstLarge << '\n';

    const int sum = std::accumulate(values.begin(), values.end(), 0);
    values.erase(std::remove_if(values.begin(), values.end(),
                                [](int value) { return value % 2 == 0; }),
                 values.end());

    std::cout << "Sum before removal: " << sum << "\nOdds: ";
    for (int value : values)
        std::cout << value << ' ';
    std::cout << '\n';
}
