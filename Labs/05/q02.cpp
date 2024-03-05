/*
* Programmer: Muhammad Umar
* Roll no: 23K-0023
*/

#include <iostream>
using namespace std;

class LoanHelper {
    const float interestRate;
    float amount;
    int amountOfMonths;
    
    public : 
        LoanHelper(float interest, float am, int months) : interestRate(interest), amount(am), amountOfMonths(months) {}
        
        void calculateLoan() {
            float repay = (amount/amountOfMonths)+((amount/amountOfMonths)*interestRate);
            cout << "You have to pay " << repay << " for " << amountOfMonths << " months to repay your loan." << endl;
        }
};

int main() {
    
    LoanHelper l(0.25/100, 50000, 10);
    
    l.calculateLoan();

    return 0;
}
