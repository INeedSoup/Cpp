#pragma once

#include <string>
#include <vector>

struct Transaction
{
    std::string description;
    double amount{};
};

double total(const std::vector<Transaction>& transactions);
