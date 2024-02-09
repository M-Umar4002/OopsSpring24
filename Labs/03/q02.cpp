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
            void setCompany(string com) {
                company = com;
            }
            
            void setColor(string clr) {
                color = clr;
            }
            
            void setCapacityInML(float cap) {
                capacityML = cap;
            }
            
            void setCapacityInL() {
                capacityLitres = capacityML/1000;
            }
            
            void updateCapacity() {
                float cap;
                cout << "Enter the capacity of water consumed in millilitres : ";
                cin >> cap;
                capacityML = cap;
                capacityLitres = capacityML/1000;
            }
            
            string getCompany() {
                return company;
            }
            
            string getColor() {
                return color;
            }
            
            float getCapacityInML() {
                return capacityML;
            }
            
            float getCapacityInL() {
                return capacityLitres;
            }
    };
    
    WaterBottle b1;
    
    b1.setCompany("Aquafina"), b1.setColor("transparent"), b1.setCapacityInML(1100.11), b1.setCapacityInL();
    
    b1.updateCapacity();
    
    cout << "Company : " << b1.getCompany() << endl << "Color : " << b1.getColor() << endl << "Capacity in litres : " << b1.getCapacityInL() << endl << "Capacity in millilitres : " << b1.getCapacityInML() << endl;

    return 0;
}
