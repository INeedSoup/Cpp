/* Learn: a struct groups related public values into one record.
Why: a Student is easier to pass around than separate name, GPA, and enrolment variables.
Use: simple data with no important invariant to enforce.
Watch out: choose a class when construction or changes must be validated.
Try next: Add a function that prints a Student through a const reference. */
#include <iostream>
#include <string>

struct Student
{
    std::string name;
    double gpa{};
    bool enrolled{true};
};

void printStudent(const Student& student)
{
    std::cout << student.name << ": GPA " << student.gpa
              << ", enrolled: " << std::boolalpha << student.enrolled << '\n';
}

int main()
{
    Student aman{"Aman", 3.5, true};
    Student ponda{"Ponda", 1.5, false};
    printStudent(aman);
    printStudent(ponda);
}
