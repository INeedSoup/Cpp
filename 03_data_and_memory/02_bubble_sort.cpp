#include <algorithm>
#include <array>
#include <iostream>

void bubbleSort(std::array<int, 6>& values)
{
    for (std::size_t pass = 0; pass + 1 < values.size(); ++pass)
    {
        bool swapped = false;
        for (std::size_t index = 0; index + 1 < values.size() - pass; ++index)
        {
            if (values[index] > values[index + 1])
            {
                std::swap(values[index], values[index + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            return; // Already sorted.
    }
}

int main()
{
    std::array<int, 6> values{10, 1, 9, 2, 5, 6};
    bubbleSort(values);
    for (int value : values)
        std::cout << value << ' ';
    std::cout << "\nBubble sort is O(n^2); prefer std::sort for real programs.\n";
}
