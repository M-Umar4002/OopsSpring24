#include <iostream>
using namespace std;

int maxximumArea(int arr[], int size) {
    
    int maxArea = -1;
    
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if ((j-i) * min(arr[i], arr[j]) > maxArea) maxArea = (j-i) * min(arr[i], arr[j]);
        }
    }
    
    return maxArea;
}

int main(){
    int size = 9, height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    
    cout << maxximumArea(height, size);

    return 0;
}
