#include <iostream>
using namespace std;

class BankAccount {
    int accountNumber;
    string accountHolderName;
    float balance;

    public : 
        BankAccount() {}

        BankAccount(int accountNumber, string accountHolderName, float balance) {
            this->accountNumber = accountNumber, this->accountHolderName = accountHolderName, this->balance = balance;
        }

        void deposit(double amount) {
            balance += amount;
        }

        void withdraw(double amount) {
            if(amount <= balance) {
                balance -= amount;
            } else {
                cout << "Your balance is insufficient" << endl;
            }
        }

        void display() {
            cout << "Account number : " << accountNumber << endl << "Account holder name : " << accountHolderName << endl << "Balance : " << balance << endl << endl;
        }
};

void displayInfo(BankAccount accounts[3]) {
    cout << endl << "Details of all accounts" << endl << endl;
    for(int i = 0; i < 3; i++) {
        cout << "Account" << i+1 << endl;
        accounts[i].display();
    }
}

int main() {
    
    BankAccount accounts[3];

    accounts[0] = BankAccount(20, "Umar", 300), accounts[1] = BankAccount(25, "Fahad", 0), accounts[2] = BankAccount(30, "Ali", 500);

    displayInfo(accounts);

    for(int i = 0; i < 3; i++) accounts[i].deposit(500);

    cout << endl << "After deposit of 200 in each account" << endl;
    displayInfo(accounts);

    for(int i = 0; i < 3; i++) accounts[i].withdraw(200);

    cout << endl << "After withdraw of 200 from each account" << endl;
    displayInfo(accounts);

    accounts[0].withdraw(1000);

    return 0;
}
