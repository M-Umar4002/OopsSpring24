#include <iostream>

using namespace std;

class Account {
    protected :
        int accountNumber;
        double balance;
        
        static int totalAccounts;
    
    public :
        Account() : accountNumber(totalAccounts++), balance(0.0) {}
    
        int getAccountNumber() const {
            return accountNumber;
        }
        
        double getBalance() const {
            return balance;
        }
        
        virtual void deposit(double amount) = 0;
        virtual void withdraw(double amount) = 0;
        virtual void calculateInterest() = 0;
};

int Account::totalAccounts = 0;

class SavingsAccount : public Account {
    double interestRate;
    
    public :
        SavingsAccount(double interestRate) : interestRate(interestRate) {}
    
        void deposit(double amount) {
            balance += amount;
        }
        
        void withdraw(double amount) {
            if(balance >= amount) {
                balance -= amount;
            } else {
                cout << "You cant withdraw Rs. " << amount << " due to insufficient balance" << endl;
            }
        }
        
        void calculateInterest() {
            balance += balance * interestRate;
        }
};

class CurrentAccount : public Account {
    double overdraftLimit;
    
    public :
        CurrentAccount(double overdraftLimit) : overdraftLimit(overdraftLimit) {}
        
        void deposit(double amount) {
            balance += amount;
        }
        
        void withdraw(double amount) {
            if(balance + overdraftLimit >= amount) {
                balance -= amount;
            } else {
                cout << "Overdraft limit exceeded" << endl;
            }
        }
        
        void calculateInterest() {
            // No interest
        }
};

int main() {
    
    return 0;
}
