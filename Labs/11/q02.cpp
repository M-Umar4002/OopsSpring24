#include <iostream>

using namespace std;

class Account {
    protected :
        int accountNumber;
        double balance;
        
        static int totalAccounts;
    
    public :
        Account() : accountNumber(++totalAccounts), balance(0.0) {}
    
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
                if(balance < 0) balance = 0;
            } else {
                cout << "Overdraft limit exceeded" << endl;
            }
        }
        
        void calculateInterest() {
            // No interest
        }
};

void displayDetails(Account* account) {
    cout << "Account Number : " << account->getAccountNumber() << endl << "Balance : Rs." << account->getBalance() << endl;
}

int main() {
    Account* savingsAccount = new SavingsAccount(0.03);
    savingsAccount->deposit(22000);
    savingsAccount->withdraw(4000);
    savingsAccount->calculateInterest();
    
    cout << "Details of Saving Account: " << endl;
    displayDetails(savingsAccount);
    
    Account* currentAccount = new CurrentAccount(10000);
    currentAccount->deposit(2000);
    currentAccount->withdraw(4000);
    currentAccount->calculateInterest();
    
    cout << endl << "Details of Current Account: " << endl;
    displayDetails(currentAccount);
    
    return 0;
}
