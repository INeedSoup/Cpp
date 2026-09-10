#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::array<int, 3> fixedScores{90, 84, 76}; // Fixed size, known at compile time.
    std::vector<int> scores{90, 84, 76};        // Resizable, contiguous: the normal default.
    scores.push_back(95);

    std::deque<int> queueLike{2, 3};
    queueLike.push_front(1);
    queueLike.push_back(4); // Efficient at both ends.

    std::list<int> linked{1, 2, 3};
    linked.push_front(0); // Cheap insertion with an iterator; no random indexing.

    std::cout << "Last score: " << scores.back() << "\nFixed first: " << fixedScores.front()
              << "\nDeque size: " << queueLike.size() << "\nList front: " << linked.front() << '\n';
}
