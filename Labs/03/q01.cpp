/*
* Name: Muhammad Umar
* Roll No: 23K-0023
*/

#include <iostream>
using namespace std;

class BoardMarker {
    string brand, shade;
    bool refillable, status;

    public :
        void setBrand(string b) {
            brand = b;
        }
        
        void setShade(string s) {
            shade = s;
        }
        
        void setRefillabilty(bool ref) {
            refillable = ref;
        }
        
        void setStatus(bool stat) {
            status = stat;
        }

        void writing() {
            cout << (status ? "Ink is depleted" : "Ink is not depleted") << endl; 
        }

        void refill() {
            cout << (refillable ? "Can be refilled" : "Cant be refilled") << endl; 
        }
        
        string getBrand() {
            return brand;
        }
        
        string getShade() {
            return shade;
        }
        
        bool getRefillability() {
            return refillable;
        }
        
        bool getStatus() {
            return status;
        }
};

int main() {

    BoardMarker m1;

    m1.setBrand("Dollar"), m1.setShade("Black"), m1.setRefillabilty(false), m1.setStatus(true);
    
    cout << "Brand : " << m1.getBrand() << endl << "Shade : " << m1.getStatus() << endl << "Refillable : " << (m1.getRefillability() ? "Yes" : "No") << endl << "Status : " << (m1.getStatus() ? "depleted" : "Not depleted") << endl;
    
    m1.writing();
    m1.refill();

    return 0;
}
