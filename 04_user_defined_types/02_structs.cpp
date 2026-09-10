#include <iostream>

struct student
{
    std::string name;
    double gpa;
    bool enrolled = true; // default value can be set so only explicitly set values will overwrite it else default value will be considered
};

struct Car
{
    std::string model;
    int year;
    std::string color;
};

void printCar(Car car); // pass by value

void printCar1(Car &car); // Pass by reference

void paintCar(Car &car, std::string colour);

int main()
{
    // struct : a structure that group related variables under one name, struct can contain many different data types, variables in a struct are known as "members"
    // Members can be accessed with "Class member access operator"

    student student1;
    student1.name = "Aman";
    student1.gpa = 3.5;
    student1.enrolled = true;
    std::cout << student1.name << " " << student1.gpa << " " << student1.enrolled << "\n";

    student student2;
    student2.name = "Pawar";
    student2.gpa = 2.7;
    student2.enrolled = true;
    std::cout << student2.name << " " << student2.gpa << " " << student2.enrolled << "\n";

    student student3;
    student3.name = "Ponda";
    student3.gpa = 1.5;
    student3.enrolled = false;
    std::cout << student3.name << " " << student3.gpa << " " << student3.enrolled << "\n";
    
    Car car1;
    car1.model = "Mustang";
    car1.year = 2023;
    car1.color = "red";

    Car car2;
    car2.model = "Corvette";
    car2.year = 2024;
    car2.color = "blue";

    std::cout << &car1 << " ";
    printCar(car1);
    std::cout << "\n";
    
    std::cout << &car2 << " ";
    printCar1(car2);

    paintCar(car2, "cyan");
    printCar(car2);

    return 0;
}

void printCar(Car car)
{
    std::cout << &car << " ";
    std::cout << car.model << " " << car.year << " " << car.color << "\n";
}

void printCar1(Car &car)
{
    std::cout << &car << " ";
    std::cout << car.model << " " << car.year << " " << car.color << "\n";
}

void paintCar(Car &car, std::string color)
{
    car.color = color;
}