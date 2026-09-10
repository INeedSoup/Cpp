#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>

int main()
{
    std::set<int> sortedUnique{4, 1, 4, 2}; // Unique and ordered: 1, 2, 4.
    std::unordered_set<std::string> seen{"red", "blue"}; // Fast average lookup; no order.

    std::map<std::string, int> orderedMarks{{"Asha", 92}, {"Bala", 87}};
    std::unordered_map<std::string, int> frequency;
    for (const char* word : {"red", "blue", "red"})
    {
        ++frequency[word];
    }

    std::cout << "Contains 2: " << sortedUnique.contains(2) << '\n';
    std::cout << "Seen blue: " << seen.contains("blue") << '\n';
    std::cout << "Asha: " << orderedMarks.at("Asha") << '\n';
    std::cout << "red count: " << frequency["red"] << '\n';
}
