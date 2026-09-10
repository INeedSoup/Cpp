#include <iostream>

int main()
{
    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    if(name.length() > 12)
    {
        std::cout << "Your name can't be above 12 characters\n";
    }
    else
    {
        std::cout << "Welcome " << name << std::endl;
    }

    if(name.empty())
    {
        std::cout << "You didnt enter your name\n";
    }
    else
    {
        std::cout << "Hello " << name << std::endl;
    }

    name.clear();
    std::cout << "Hello " << name << std::endl;

    std::cout << "Enter our name again: ";
    std::getline(std::cin, name);
    name.append("@gmail.com");
    std::cout << "Your username is now " << name << std::endl;

    std::cout << name.at(0);

    name.insert(0, "d");
    std::cout << name << std::endl;

    std::cout << name.find(' ') << std::endl;

    name.erase(0, 3);
    std::cout << name << std::endl;

    return 0;
}