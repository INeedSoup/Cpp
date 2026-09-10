#include <iostream>

void swapPBV(std::string x, std::string y);

void swapPBR(std::string &x, std::string &y);


int main()
{
    // memory address = a location in memory where data is stored, a memory address can be accessed with &(address-of operator)

    std::string name = "Aman";
    int age = 22;
    bool student = false;

    std::cout << &name << "\n"; // hexadecimal address
    std::cout << *&name << "\n"; // *(dereference operator, value-of operator, to retrieve value at a given address)
    std::cout << &age << "\n";
    std::cout << &student << "\n\n\n";

    std::string x = "Kool-Aid";
    std::string y = "Water";
    std::cout << &x << "\n";
    std::cout << &y << "\n";

    swapPBV(x, y); // pass by value, we send a copy of values to function so our real values stay uneffected
    std::cout << "X: " << x << "\n" << "Y: " << y << "\n\n";

    
    std::cout << &x << "\n";
    std::cout << &y << "\n\n";
    swapPBR(x, y); // pass by reference, we work directly on variables 
    std::cout << "X: " << x << "\n" << "Y: " << y << "\n\n";

    return 0;
}

void swapPBV(std::string x, std::string y)
{
    std::string temp = x;
    x = y;
    y = temp;
    std::cout << &x << "\n";
    std::cout << &y << "\n";
}

void swapPBR(std::string &x, std::string &y)
{
    std::string temp = x;
    x = y;
    y = temp;
    std::cout << &x << "\n";
    std::cout << &y << "\n";
}
