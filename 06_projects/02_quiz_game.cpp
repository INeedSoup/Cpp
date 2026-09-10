#include <iostream>
#include <cctype>

int main()
{
    std::string questions[] = {"1. What year was C++ created?: ", 
                              "2. Who created C++?: ",
                              "3. What is the predecessor of C++?: ",
                              "4. Is the earth flat?: "};

    std::string options[][4] = {{"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
                                {"A. Guido Van Rossum", "B. Bjarne Stroustrup", "C. John Carmack", "D. Mark Zuckerburg"},
                                {"A. C", "B. C+", "C. C--", "D. D++"},
                                {"A. Yes", "B. No", "C. Sometimes", "D. Whats Earth"}};
    
    char answerKey[] = {'C', 'B', 'A', 'B'};

    constexpr std::size_t size = sizeof(questions)/sizeof(questions[0]);
    
    char guess; int score = 0;

    for(std::size_t i = 0; i < size; i++)
    {
        std::cout << "***************************************\n";
        std::cout << questions[i] << "\n";
        std::cout << "***************************************\n";
        
        for(std::size_t j = 0; j < sizeof(options[i])/sizeof(options[i][0]); j++)
        {
            std::cout << options[i][j] << "\n";
        }

        std::cin >> guess;
        guess = static_cast<char>(std::toupper(static_cast<unsigned char>(guess)));

        if(guess == answerKey[i])
        {
            std::cout << "Correct\n";
            score++;
        }
        else
        {
            std::cout << "Wrong\n";
            std::cout << "Answer: " << answerKey[i] << "\n";
        }
    }
    std::cout << "***************************************\n";
    std::cout << "You scored " << score << " out of " << size << "\n";
    std::cout << "Percentage: " << (score / static_cast<double>(size)) * 100 << "%\n"; 
    std::cout << "***************************************\n";

    return 0;
}
