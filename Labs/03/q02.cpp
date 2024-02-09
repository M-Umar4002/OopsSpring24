/*
* Name: Muhammad Umar
* Roll No: 23K-0023
*/

#include <iostream>
using namespace std;

int main(){
    
    class WaterBottle {
        string company, color;
        float capacityLitres, capacityML;
    
        public :
            void setData(string com, string col, float capML) {
                company = com, color = col, capacityML = capML;
            }
            
            void updateCapacity() {
                float cap;
                cout << "Enter new capacity of water bottle in millilitres : ";
                cin >> cap;
                capacityML = cap;
            }
        
            void getData() {
                capacityLitres = capacityML/1000;
                cout << "Company : " << company << endl << "Color : " << color << endl << "Capacity in litres : " << capacityLitres << endl << "Capacity in millilitres : " << capacityML << endl;
            }
    };
    
    WaterBottle b1;
    
    b1.setData("Aquafina", "transparent", 1100.11);
    b1.updateCapacity();
    b1.getData();

    return 0;
}
