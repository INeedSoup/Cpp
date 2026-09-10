#include "ledger.h"

#include <iostream>
#include <vector>

int main()
{
    const std::vector<Transaction> transactions{{"Salary", 1000.0}, {"Books", -35.0}};
    std::cout << "Balance: " << total(transactions) << '\n';
}
