/* Learn: a random engine produces values and a distribution constrains them to a useful range.
Why: modern <random> makes the source and range explicit.
Watch out: seed once; repeatedly reseeding can reduce randomness.
Try next: Roll two dice and add their values. */
#include <iostream>
#include <random>

int main()
{
    // Seed once. Unlike rand(), the engine and distribution make the range explicit.
    std::random_device device;
    std::mt19937 engine(device());
    std::uniform_int_distribution<int> die(1, 6);

    std::cout << "Rolling a die three times: ";
    for (int roll = 0; roll < 3; ++roll)
    {
        std::cout << die(engine) << ' ';
    }
    std::cout << '\n';

    std::uniform_int_distribution<int> answer(1, 100);
    const int secret = answer(engine);
    std::cout << "A number-guessing game would keep this secret: " << secret << '\n';
}
