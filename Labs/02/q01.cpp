/*
* Name: Muhammad Umar
* Roll No: 23K-0023
*/

#include <iostream>
#include <string>
using namespace std;

void recursiveSwap(int &a, int &b, int n = 3) {
    
    if(!n) return;
    
    a ^= b;
    
    recursiveSwap(b, a, n - 1);
}

int main() {
    
    int x = 4, y = 5;
    
    cout << "Before Swap : " << endl << "x = " << x << endl << "y = " << y << endl << endl;
    
    recursiveSwap(x, y);
    
    cout << "After Swap : " << endl << "x = " << x << endl << "y = " << y;
}
