#include <iostream>
using namespace std;

class RollerCoaster {
    string name;
    float height, length, speed;
    int capacity, currentNumRiders;
    bool rideInProgress;
    
    public : 
        RollerCoaster() {
            name = "roller coaster", height = 500, length = 2000, speed = 0, capacity = 20, rideInProgress = false, currentNumRiders = 0;
        }
    
        RollerCoaster(string n, float l, float h, float s, int cap) {
            name = n, height = h, length = l, speed = s, currentNumRiders = 0;
            
            capacity = cap > 3 ? (!cap % 2 || !cap % 3 ? cap : cap + 1) : 20; 
        }
        
        void setter(string n, float l, float h, float s, int cap) {
            name = n, height = h, length = l, speed = s, currentNumRiders = 0;
            
            capacity = cap > 3 ? (!cap % 2 || !cap % 3 ? cap : cap + 1) : 20; 
        }
        
        void getter(){
            cout << endl << "Roller Coaster's name : " << name << endl << "Maximum height it can reach : " << height << endl << "Total length of track : " << length << endl << "Speed of roller coaster : " << speed << endl << "Maximum people that can be seated once : " << capacity << endl << "Number of people seated currently : " << currentNumRiders << endl << "Is the ride in progress : " << (rideInProgress ? "Yes" : "No") << endl;
        }
        
        int loadRiders(int riders) {
            if(!rideInProgress) {
                if(riders <= capacity) {
                    currentNumRiders = riders;
                    return 0;
                }
                else return riders-capacity;
            } else {
                cout << "Ride is in Progress" << endl;
                return -1;
            }
        }
        
        int startRide() {
            if(!rideInProgress) {
                rideInProgress = true;
                cout << "Ride is started" << endl;
                if(currentNumRiders == capacity) return 0;
                else return capacity-currentNumRiders;
            } 
            else return -1;
        }
        
        void stopRide() {
            if(rideInProgress) {
                rideInProgress = false;
                cout << "Ride is stopped" << endl;
            }
            else cout << "The ride is already not in progress" << endl;
        }
        
        void unloadRiders() {
            if(!rideInProgress && currentNumRiders > 0) {
                currentNumRiders = 0;
                cout << "Riders are overloaded" << endl;
            }
            else cout << "The ride is in progress so cant unload the riders. Stop the ride to unload the riders";
        }
        
        float accelerate() {
            return speed *= 3;
        }
        
        float applyBrake() {
            return speed /= 2;
        }
};

int main(){
    
    RollerCoaster r1;
    
    r1 = RollerCoaster("Roller Coaster 1", 1000, 300, 30, 30);
    
    RollerCoaster r2;
    cout << "Information of object 2 using default constructor" << endl;
    r2.getter();
    
    r2 = RollerCoaster("Roller Coaster 2", 1500, 600, 70, 25);
    cout << endl << endl << endl << "Information of object 2 using parametrized constructor" << endl;
    r2.getter();
    
    r2.setter("ROLLER COASTER 2", 2500, 700, 100, 35);
    cout << endl << endl << endl << "Information of object 2 using setter function" << endl;
    r2.getter();
    
    cout << endl << endl << endl << "Applying all other functionality" << endl << endl;
    
    if(!r2.loadRiders(15)) {
        cout << "All riders are loaded into roller coaster" << endl;
        if(r2.startRide() != 0 && r2.startRide() != -1) {
            cout << r2.startRide() << "seats left in the ride" << endl;
        }
    } else if(r2.loadRiders(15) != -1){
        cout << "There is not much capacity to load these much riders" << endl;
    }
    
    cout << "On applying acceleration, speed becomes : " << r2.accelerate() << endl << "Then, on applying brake speed becomes : " << r2.applyBrake() << endl;
    
    r2.stopRide(), r2.unloadRiders();
    
    cout << endl << endl << endl << "Now printing information of object 2 after applying all the functionality" << endl;
    r2.getter();
    
    return 0;
}
