#include <iostream>

int myNum = 3;

void printNum(int myNum);

void printNum();

int main()
{
    int myNum = 1;

    printNum();
    printNum(myNum);

    std::cout << "local value: " << myNum << std::endl;

    std::cout << "Global value: " << ::myNum << std::endl; 

    return 0;
}

void printNum(int myNum)
{
    std::cout << "Value passed by main function: " << myNum << std::endl;
    
    std::cout << "Global value: " << ::myNum << std::endl;
}

void printNum()
{
    int myNum = 2;
    std::cout << "local value to printNum function: " << myNum << std::endl;
}