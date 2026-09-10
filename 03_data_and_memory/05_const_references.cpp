#include <iostream>
#include <string>

void printInfo(const std::string& name, int age)
{
    // The reference avoids copying a potentially large string; const prevents modification.
    std::cout << name << " is " << age << " years old.\n";
}

int main()
{
    const std::string name = "Aman";
    printInfo(name, 21);
}
