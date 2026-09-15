/* Learn: a class bundles state and operations, and private data protects its rules.
Why: BankAccount prevents callers from directly creating an invalid balance.
Use: a type has behaviour or an invariant that must always hold.
Watch out: inheritance should mean “is a”; it is not a shortcut for ordinary code reuse.
Try next: Add a withdraw function that rejects an amount larger than the balance. */
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

class BankAccount
{
public:
    BankAccount(std::string owner, double openingBalance)
        : owner_(std::move(owner)), balance_(openingBalance) // Initializer lists construct members directly.
    {
        if (openingBalance < 0.0)
            throw std::invalid_argument("Opening balance cannot be negative.");
    }

    void deposit(double amount)
    {
        if (amount <= 0.0)
            throw std::invalid_argument("Deposit must be positive.");
        balance_ += amount;
    }

    [[nodiscard]] double balance() const { return balance_; } // [[nodiscard]] asks callers not to ignore this result.
    [[nodiscard]] const std::string& owner() const { return owner_; }

private:
    std::string owner_;
    double balance_{}; // Private data protects the class invariant.
};

class Vehicle
{
public:
    explicit Vehicle(std::string brand) : brand_(std::move(brand)) {}
    void start() const { std::cout << brand_ << " starts.\n"; }

protected:
    std::string brand_;
};

class ElectricCar : public Vehicle
{
public:
    ElectricCar(std::string brand, int batteryPercent)
        : Vehicle(std::move(brand)), batteryPercent_(batteryPercent) {}

    void charge() { batteryPercent_ = 100; }
    void showStatus() const { std::cout << brand_ << " battery: " << batteryPercent_ << "%\n"; }

private:
    int batteryPercent_{};
};

int main()
{
    BankAccount account{"Aman", 500.0};
    account.deposit(125.0);
    std::cout << account.owner() << " has " << account.balance() << '\n';

    ElectricCar car{"Tesla", 42};
    car.start();
    car.charge();
    car.showStatus();
}
