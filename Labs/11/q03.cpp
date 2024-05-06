#include <iostream>

using namespace std;

class Vehicle {
    protected :
        string make, model;
        int speed;
    
    public :
        Vehicle(string make, string model) : make(make), model(model), speed(0) {}
        
        string getMake() const {
            return make;
        }
        
        string getModel() const {
            return model;
        }
        
        int getSpeed() const {
            return speed;
        }
        
        virtual void accelerate() = 0;
        virtual void brake() = 0;
        virtual void calculateFuelEfficiency() = 0;
};

class Car : public Vehicle {
    double fuelCapacity;
    
    public :
        Car(string make, string model, double fuelCapacity) : Vehicle(make, model), fuelCapacity(fuelCapacity) {}
        
        void accelerate() {
            speed += 12;
        }
        
        void brake() {
            speed = speed - 4 > 0 ? speed - 4 : 0;
        }
        
        void calculateFuelEfficiency() {
            cout << "Fuel efficiency : " << speed / fuelCapacity << " km/L" << endl;
        }
};

class Truck : public Vehicle {
    int cargoCapacity;
    
    public :
        Truck(string make, string model, int cargoCapacity) : Vehicle(make, model), cargoCapacity(cargoCapacity) {}
        
        void accelerate() {
            speed += 7;
        }
        
        void brake() {
            speed = speed - 2 > 0 ? speed - 2 : 0;
        }
        
        void calculateFuelEfficiency() {
            cout << "Fuel efficiency is calculated based on cargo capacity and speed." << endl;
        }
};

void displayDetails(Vehicle* vehicle) {
    cout << "Make : " << vehicle->getMake() << endl << "Model : " << vehicle->getModel() << endl << "Speed : " << vehicle->getSpeed() << " km/hr" << endl;
    vehicle->calculateFuelEfficiency();
}

int main() {
    Vehicle* car = new Car("Toyota", "Camry", 50);
    car->accelerate();
    car->brake();
    
    cout << "Details of car: " << endl;
    displayDetails(car);
    
    Vehicle* truck = new Truck("Ford", "F-150", 5000);
    truck->accelerate();
    truck->brake();
    
    cout << endl << "Details of truck: " << endl;
    displayDetails(truck);
    
    return 0;
}
