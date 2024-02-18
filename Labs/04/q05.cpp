#include <iostream>
#include <array>
using namespace std;

class Office {
    string location = "";
    int seatingCapacity = 0;
    string* furniture;
    
    public : 
        Office(string loc = "", int cap = 0, int size = 3) : location(loc), seatingCapacity(cap) {
            furniture = new string[size];
        }
        
        ~Office() {
            delete[] furniture;
        }
        
};

int main() {

    Office* o1 = new Office("Saddar", 30, 5);
    
    delete o1;

    return 0;
}
