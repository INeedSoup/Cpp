/* Learn: virtual functions let a base-class reference call the correct derived behaviour at runtime.
Why: one function can work with several kinds of related object without knowing the exact kind.
Use: model a real “is-a” relationship with a shared interface.
Watch out: a polymorphic base class needs a virtual destructor; prefer composition when there is no true is-a relationship.
Try next: Add a Bird class with its own sound. */
#include <iostream>
#include <string>

class Animal
{
public:
    virtual ~Animal() = default;
    virtual std::string sound() const = 0; // = 0 makes sound a required derived-class operation.
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

void introduce(const Animal& animal)
{
    std::cout << "The animal says " << animal.sound() << '\n'; // Dynamic dispatch happens here.
}

int main()
{
    const Dog dog;
    const Cat cat;
    introduce(dog);
    introduce(cat);
}
