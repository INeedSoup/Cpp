#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Animal
{
public:
    virtual ~Animal() = default;
    virtual std::string sound() const = 0; // A pure virtual function makes this an interface.
};

class Dog final : public Animal
{
public:
    std::string sound() const override { return "woof"; }
};

class Cat final : public Animal
{
public:
    std::string sound() const override { return "meow"; }
};

int main()
{
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());

    for (const auto& animal : animals)
    {
        std::cout << animal->sound() << '\n';
    }
    // unique_ptr automatically destroys each object when animals goes out of scope.
}
