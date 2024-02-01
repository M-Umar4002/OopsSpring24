/*
* Name: Muhammad Umar
* Roll No: 23K-0023
*/

#include <iostream>
using namespace std;

bool hasSubsetSum(int arr[], int size, int targetSum) {
    
    static int z = 0;
    int i = z++;
    
    if(i == size) return false;
    
    int sum = 0;
    while(i < size){
        sum += arr[i++];
        if(sum == targetSum) return true;
    }
    
    return hasSubsetSum(arr, size, targetSum);
}

int main() {
    
    int arr[] = {1, 2, 3, 4, 5, 6}, targetSum = 9;
    
    cout << (hasSubsetSum(arr, sizeof(arr) / sizeof(int), targetSum) ? "There’s a subset of the array whose elements sum up to the target sum" : "There’s not a subset of the array whose elements sum up to the target sum");
}
