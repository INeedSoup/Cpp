/* Learn: a declaration introduces a function; a definition provides its body; overloads share a name but differ in parameters.
Why: functions give a repeated task one reliable implementation.
Use: extract a block when its name explains the caller better than the block itself.
Watch out: parameter types—not return types—distinguish overloads.
Try next: Add an overload that calculates the area of a rectangle. */
#include <iostream>
#include <string>

double square(double value);
double area(double side);
double area(double width, double height);
std::string joinNames(const std::string& first, const std::string& last);

int main()
{
    std::cout << "Square: " << square(5.0) << '\n';
    std::cout << "Square area: " << area(4.0) << '\n';
    std::cout << "Rectangle area: " << area(4.0, 3.0) << '\n';
    std::cout << "Hello, " << joinNames("Aman", "Pawar") << "!\n";
}

double square(double value) { return value * value; }
double area(double side) { return side * side; }
double area(double width, double height) { return width * height; }
std::string joinNames(const std::string& first, const std::string& last) { return first + " " + last; }
