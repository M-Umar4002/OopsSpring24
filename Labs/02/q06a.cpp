/*
* Name: Muhammad Umar
* Roll No: 23K-0023
*/

#include <iostream>
using namespace std;

int calculateLCM(int num1, int num2) {
    
    static int n = max(num1, num2);
    
    if(!(n % num1) && !(n % num2)) return n;
    
    n++;
    
    return calculateLCM(num1, num2);
}

int calculateGCD(int num1, int num2) {
    
    static int n = min(num1, num2);
    
    if(!(num1 % n) && !(num2 % n)) return n;
    
    n--;
    
    return calculateGCD(num1, num2);
}

int main() {
    int num1 = 6, num2 = 9;
    
    cout << "LCM : " << calculateLCM(num1, num2) << endl << "GCD : " << calculateGCD(num1, num2);
}
