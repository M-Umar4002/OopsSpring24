#include <iostream>
using namespace std;

class BankAccount {
    int accountId;
    double balance;
    int* transactionHistory;
    int numTransactions;
    
    public :
        BankAccount(int id, double bal, int trans) : accountId(id), balance(bal), numTransactions(trans) {
            transactionHistory = new int[numTransactions];
            cout << "Enter details of transactions history" << endl;
            for(int i = 0; i < numTransactions; i++) {
                cout << "Enter transaction history " << i+1 << " : ";
                cin >> transactionHistory[i];
            }
        }

        BankAccount(BankAccount &obj) {
            accountId = obj.accountId, balance = obj.balance, numTransactions = obj.numTransactions;
            transactionHistory = new int[numTransactions];

            for (int i = 0; i < numTransactions; i++) transactionHistory[i] = obj.transactionHistory[i];
            
        }

        ~BankAccount() {
            delete [] transactionHistory;
        }

        void updateTransactionHistory() {

            delete [] transactionHistory;

            cout << "Enter new number of transactions : ";
            cin >> numTransactions;

            transactionHistory = new int[numTransactions];

            cout << "Enter details of new transactions history" << endl;
            for(int i = 0; i < numTransactions; i++) {
                cout << "Enter transaction history " << i+1 << " : ";
                cin >> transactionHistory[i];
            }
        }

        void display() const {
            cout << "Account Id : " << accountId << endl << "Balance : " << balance << endl;

            for(int i = 0; i < numTransactions; i++) cout << "Transaction History " << i+1 << " : " << transactionHistory[i] << endl;
        }
};

int main() {

    BankAccount account1(200, 20000, 3);

    BankAccount account2(account1);

    cout << "Before updating transaction history" << endl << endl << "Details of account 1" << endl;
    account1.display();

    cout << endl << "Details of account 2" << endl;
    account2.display();
    
    cout << endl << endl;

    account1.updateTransactionHistory();

    cout << endl << endl << "After updating transaction history" << endl << endl << "Details of account 1" << endl;
    account1.display();

    cout << endl << "Details of account 2" << endl;
    account2.display();

    return 0;
}
