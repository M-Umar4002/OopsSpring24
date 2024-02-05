#include <iostream>
using namespace std;

int calculateLCM(int num1, int num2) {
    static int maxNum = max(num1, num2), minNum = min(num1, num2), ans = maxNum;
    if(!(ans % minNum)) return ans;
    ans += maxNum;
    return calculateLCM(num1, num2);
}

int calculateGCD(int num1, int num2) {
    if (!num2) return num1;
    return calculateGCD(num2, num1 % num2);
}

int main() {
    cout << "LCM : " << calculateLCM(6, 9) << endl << "GCD : " << calculateGCD(6, 9);
}
