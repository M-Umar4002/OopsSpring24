#include <iostream>
using namespace std;

class Vehicle {
    string make, model;
    int year;
    
    public : 
        Vehicle(string make, string model, int year) : make(make), model(model), year(year) {}
        
        void display() {
            cout << "Make : " << make << endl << "Model : " << model << endl << "Year : " << year << endl;
        }
};

class Car : public Vehicle {
    int doors;
    float fuelEfficiency;
    
    public : 
        Car(string make, string model, int year, int doors, float fuelEfficiency) : Vehicle(make, model, year), doors(doors), fuelEfficiency(fuelEfficiency) {}
        
        void display() {
            Vehicle::display();
            cout << "Doors : " << doors << endl << "Fuel Efficiency : " << fuelEfficiency << endl;
        }
};

class ElectricCar : public Car {
    float batteryLife;
    
    public : 
        ElectricCar(string make, string model, int year, int doors, float fuelEfficiency, float batteryLife) : Car(make, model, year, doors, fuelEfficiency), batteryLife(batteryLife) {}
        
        void display() {
            Car::display();
            cout << "Battery Life : " << batteryLife << endl;
        }
};

int main() {
    ElectricCar ec("Tesla", "Model 1", 2020, 4, 130, 350);
    ec.display();
    
    return 0;
}
