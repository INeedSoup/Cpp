/* Learn: a two-dimensional array stores rows containing columns.
Why: a grid makes row/column data easier to model than a flat list.
Use: fixed-size boards, tables, and small matrices.
Watch out: built-in arrays need a compile-time column size; use vector for dynamic grids.
Try next: Calculate the total of an int 3x3 grid. */
#include <array>
#include <iostream>
#include <string>

int main()
{
    const std::array<std::array<std::string, 3>, 3> cars{{
        {"Mustang", "Escape", "F-150"},
        {"Corvette", "Equinox", "Silverado"},
        {"Challenger", "Durango", "Ram 1500"}}};

    for (const auto& row : cars)
    {
        for (const std::string& car : row)
            std::cout << car << "\t";
        std::cout << '\n';
    }
}
