#include <iostream>

void hbd(std::string name, int age);

double square(double length);

double cube(double length);

std::string concatStrings(std::string string1, std::string string2);


// Overloaded functions
void bakePizza();
void bakePizza(std::string topping); // function name with its list of paramater is called function signature
void bakePizza(std::string topping1, std::string topping2);

int main()
{
    // function = a block of reusable code 
    
    std::string name = "Aman";
    int age = 22;

    hbd(name, age);
    hbd(name, age);
    hbd(name, age);

    double length = 5.0;

    double area = square(length);
    std::cout << "Area: " << area << "cm^2\n";

    double volume = cube(length);
    std::cout << "Volume: " << volume << "cm^3\n";

    std::string firstName = "Aman";
    std::string lastName = "Pawar";

    std::string fullName = concatStrings(firstName, lastName);

    std::cout << "Hello " << fullName << std::endl;

    bakePizza();
    bakePizza("pepperoni");
    bakePizza("pepperoni", "jalapenos");

    // return = return a value back to the spot where you called the encompassing function, return type should match the function type from which it is going to be return the value
    return 0;
}

void hbd(std::string name, int age)
{
    std::cout << "Happy birthday to you " << name << std::endl;
    std::cout << "You are " << age << " years old" << std::endl;
}

double square(double length)
{
    return length * length;
}

double cube(double length)
{
    return length * length * length;
}

std::string concatStrings(std::string string1, std::string string2)
{
    return string1 + " " + string2;
}

void bakePizza()
{
    std::cout << "Here is your pizza\n";
}

void bakePizza(std::string topping1)
{
    std::cout << "Here is your " << topping1 << " pizza\n";
}

void bakePizza(std::string topping1, std::string topping2)
{
    std::cout << "Here is your " << topping1 << " and " << topping2 << " pizza\n";
}