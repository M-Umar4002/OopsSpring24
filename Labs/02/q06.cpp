/*
* Name: Muhammad Umar
* Roll No: 23K-0023
*/

#include <iostream>
using namespace std;

int calculateLCM(int num1, int num2, int n) {
    if(!(n % num1) && !(n % num2)) return n;
    
    return calculateLCM(num1, num2, n + 1);
}

int calculateGCD(int num1, int num2, int n) {
    if(!(num1 % n) && !(num2 % n)) return n;
    
    return calculateGCD(num1, num2, n - 1);
}

int main() {
    int num1 = 6, num2 = 9;
    
    cout << "LCM : " << calculateLCM(num1, num2, max(num1, num2)) << endl << "GCD : " << calculateGCD(num1, num2, min(num1, num2));
}
