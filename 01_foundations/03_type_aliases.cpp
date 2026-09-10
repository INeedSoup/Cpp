#include <iostream>

typedef std::string text_t; 

// type def : reserved keyword used to create an additional (alais) for another data type
// new identifier for an existing type
// helps us with readablity and reduces typos
// use when there is a clear benefit
// replaced with 'using' (work better w/ templates)

using number_t = int;


int main()
{
    text_t firstName = "Aman";

    std::cout << firstName << "\n";
    
    number_t x = 10;
    
    std::cout << x << "\n";

    return 0;
}