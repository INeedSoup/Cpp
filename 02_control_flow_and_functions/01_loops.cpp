#include <iostream>

int main()
{
    std::string name;

    while(name.empty()) 
    {
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);
    }

    std::cout << "Hello " << name << std::endl;

    // do while loop = do some block of code first, then repeat again if condition is true

    int number = 0;

    while(number < 0)
    {
        std::cout << "Enter a positive number: ";
        std::cin >> number;
    }
    std::cout << "The number is " << number << std::endl;

    do 
    {
        std::cout << "Enter a positive number: ";
        std::cin >> number;
    }
    while(number < 0);     
    std::cout << "The number is " << number << std::endl;

    for(int i = 1; i <= 3; i++)
    {
        std::cout << "Happy New Year \n";
    }

    // use for when we know how many times to run a certain block of code, use while when their is a breaking condition  

    // break : break out of the loop
    // continue : skip current iteration

    int check = 0;

    while(1) // infinite loop
    {
        check++;
        if(check == 10) break;
        if(check == 7) continue;
        std::cout << check << std::endl;
    }


    // Nested loop, basically loop inside a loop
    for(int i = 1; i <=3; i++)
    {
        for(int j = 1; j <=10; j++)
        {
            std::cout << j << ' ';
        }
        std::cout << std::endl;
    }

    int rows; 
    int columns;
    char symbol;

    std::cout << "How many rows?: ";
    std::cin >> rows;

    std::cout << "How many column?: ";
    std::cin >> columns;

    std::cout << "Enter a symbol to use: ";
    std::cin >> symbol;

    for(int i = 1; i <=rows; i++)
    {
        for(int j = 1; j <=columns; j++)
        {
            std::cout << symbol << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}