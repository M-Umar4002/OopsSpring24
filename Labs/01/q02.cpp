#include <iostream>
using namespace std;

int main() {
    
    int size;
    cout << "Enter size of array : ";
    cin >> size;
    
    int nums[size], target;
    
    for(int i = 0; i < size; i++) {
        cout << "Enter element " << i+1 << " : ";
        cin >> nums[i];
    }
    
    cout << "Enter the target to find : ";
    cin >> target;
    
    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size; j++) {
            if(nums[i] + nums[j] == target) {
                cout << "The indices are " << i << " and " << j;
                break;
            }
        }
    }

    return 0;
}
