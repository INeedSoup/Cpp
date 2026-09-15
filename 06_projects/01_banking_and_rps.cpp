/* Learn: projects combine small functions, state, validation, menus, and output formatting.
Why: separating responsibilities makes a program easier to test and extend.
Watch out: every user-input path needs recovery after a failed read.
Try next: Add a transaction-history vector to the banking program. */
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>

double readPositiveAmount(const char* prompt)
{
    double amount{};
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> amount && amount > 0.0)
            return amount;
        std::cout << "Enter a positive amount.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void bankingProgram()
{
    double balance = 0.0;
    int choice{};
    do
    {
        std::cout << "\n1. Balance  2. Deposit  3. Withdraw  4. Exit\n> ";
        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = 0;
        }

        switch (choice)
        {
        case 1:
            std::cout << std::fixed << std::setprecision(2) << "Balance: $" << balance << '\n';
            break;
        case 2:
            balance += readPositiveAmount("Deposit amount: $");
            break;
        case 3:
        {
            const double amount = readPositiveAmount("Withdraw amount: $");
            if (amount > balance)
                std::cout << "Insufficient funds.\n";
            else
                balance -= amount;
            break;
        }
        case 4:
            std::cout << "Thanks for banking with us.\n";
            break;
        default:
            std::cout << "Choose a number from 1 to 4.\n";
        }
    } while (choice != 4);
}

char readPlayerChoice()
{
    char choice{};
    do
    {
        std::cout << "Choose (r)ock, (p)aper, or (s)cissors: ";
        std::cin >> choice;
    } while (choice != 'r' && choice != 'p' && choice != 's');
    return choice;
}

const char* nameOf(char choice)
{
    switch (choice)
    {
    case 'r': return "rock";
    case 'p': return "paper";
    default: return "scissors";
    }
}

void rockPaperScissors()
{
    const char player = readPlayerChoice();
    std::mt19937 engine(std::random_device{}());
    std::uniform_int_distribution<int> pick(0, 2);
    const char options[]{'r', 'p', 's'};
    const char computer = options[pick(engine)];

    std::cout << "You chose " << nameOf(player) << "; computer chose " << nameOf(computer) << ".\n";
    if (player == computer)
        std::cout << "Tie.\n";
    else if ((player == 'r' && computer == 's') || (player == 'p' && computer == 'r') ||
             (player == 's' && computer == 'p'))
        std::cout << "You win.\n";
    else
        std::cout << "Computer wins.\n";
}

int main()
{
    int choice{};
    std::cout << "1. Banking program\n2. Rock-paper-scissors\n> ";
    std::cin >> choice;
    if (choice == 1)
        bankingProgram();
    else if (choice == 2)
        rockPaperScissors();
    else
        std::cout << "Choose 1 or 2.\n";
}
