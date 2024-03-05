/*
* Programmer: Muhammad Umar
* Roll no: 23K-0023
*/

#include <iostream>
using namespace std;

class Square {
    float sideLength, area;
    static float allAreas;
    
    public : 
        Square() {}
        
        Square(float sideLength) {
            this->sideLength = sideLength;
        }
        
        void setSideLength(float length) {
            sideLength = length;
        }
        
        void calculateArea() {
            area = sideLength*sideLength;
            allAreas += area;
        }
        
        float getSideLength() {
            return sideLength;
        }
        
        float getArea() {
            return area;
        }
        
        float getAllAreas() {
            return allAreas;
        }
};

float Square :: allAreas = 0.0;

int main() {
    
    Square s[3];
    s[0] = Square(3), s[1] = Square(4), s[2] = Square(5);
    
    for(int i = 0; i < 3; i++) {
        s[i].calculateArea();
        cout << "After calling calculateArea function for square " << i+1 << endl << "Area : " << s[i].getArea() << endl << "All areas : " << s[i].getAllAreas() << endl << endl;
    }

    return 0;
}
