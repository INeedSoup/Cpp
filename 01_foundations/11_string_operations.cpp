/*
Learn: std::string owns text and offers size, search, insertion, and removal operations.
Why: It is safer and more convenient than manually managed character arrays.
Use: Store and process names, sentences, and messages.
Watch out: Check that text is non-empty before accessing character 0; find can return npos.
Try next: Search for '@' and report whether the input resembles an email address.
*/
#include <iostream>
#include <string>

int main()
{
    std::string name;
    std::cout << "Enter your full name: ";
    std::getline(std::cin, name);

    if (name.empty())
    {
        std::cout << "No name was entered.\n";
        return 0;
    }
    std::cout << "Length: " << name.size() << "\nFirst character: " << name.at(0) << '\n';

    const std::size_t space = name.find(' ');
    if (space != std::string::npos)
        std::cout << "First word: " << name.substr(0, space) << '\n';
    else
        std::cout << "The name contains one word.\n";

    name.insert(0, "Learner: ");
    name.append("!");
    std::cout << name << '\n';
}
