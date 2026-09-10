#include "ledger.h"

#include <numeric>

double total(const std::vector<Transaction>& transactions)
{
    return std::accumulate(transactions.begin(), transactions.end(), 0.0,
                           [](double runningTotal, const Transaction& transaction) {
                               return runningTotal + transaction.amount;
                           });
}
