#include <iostream>
using namespace std;

int maximumArea(int arr[], int size) {
    
    int maxArea = 0;
    
    for(int i = 0; i < size; i++) for(int j = i + 1; j < size; j++) maxArea = max(maxArea, (j-i) * min(arr[i], arr[j]));
    
    return maxArea;
}

int main() {
    
    int size = 9, height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    
    cout << maximumArea(height, size);

    return 0;
}
