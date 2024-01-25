#include <iostream>
using namespace std;

bool checkPrime(int n) {
    for(int i = 2; i*i < n; i++) if (!(n % i)) return false;
    return true;
}

int main() {
    
    int num;
    cout << "Enter a number : ";
    cin >> num;

    cout << (checkPrime(num) ? "It is prime number" : "It is not a prime number");

    return 0;
}
