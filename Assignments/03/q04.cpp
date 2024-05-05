#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>

using namespace std;

class Drone {
    protected : 
        float latitude, longitude, altitude, speed;
    
    public :
        Drone(float latitude, float longitude, float altitude, float speed) : latitude(latitude), longitude(longitude), altitude(altitude), speed(speed) {}
    
        virtual void adjustAltitude(float meters) = 0;
        
        virtual void setSpeed(float speed) = 0;
};

class Flyable {
    public :
        virtual void takeOff() = 0;
        
        virtual void land() = 0;
        
        virtual void navigateTo(float latitude, float longitude, float altitude) = 0;
};

class Scannable {
    public :
        virtual void scanArea(float radius) = 0;
};

class ReconDrone : public Drone, public Flyable, public Scannable {
    float cameraResolution, maxFlightTime;
    
    public : 
        ReconDrone(float latitude, float longitude, float altitude, float speed, float cameraResolution, float maxFlightTime) : Drone(latitude, longitude, altitude, speed), cameraResolution(cameraResolution), maxFlightTime(maxFlightTime) {}
    
        void adjustAltitude(float meters) {
            altitude = meters;
        }
        
        void setSpeed(float speed) {
            this->speed = speed;
        };
        
        void takeOff() {
            cout << "Taking Off" << endl;
        }
        
        void land() {
            cout << "Landing" << endl;
        }
        
        void navigateTo(float latitude, float longitude, float altitude) {
            try {
                float x = latitude - this->latitude + cos((this->latitude + latitude) / 2);
                float y = longitude - this-> longitude;
                float distance = sqrt(x*x + y*y) * 111.f;
                float time = distance / speed;
                
                if (this->altitude > altitude) {
                    // Adjust time for climbing
                    time += (this->altitude - altitude) / 20.0f; // Assuming climbing speed of 20 meters per hour
                } else if (this->altitude < altitude) {
                    // Adjust time for descending
                    time += (altitude - this->altitude) / 30.0f; // Assuming descending speed of 30 meters per hour
                }
                
                cout << "Estimated time to reach destination: " << time << " hours" << endl;
                
                this->latitude = latitude, this->longitude = longitude, this->altitude = altitude;
            } catch(const exception &e) {
                cout << "Error during navigation : " << e.what() << endl;
            }
        }
        
        void scanArea(float radius) {
            try {
                // Simulate scanning the environment
                int objectsDetected = rand() % 10; // Random number of objects detected
                cout << endl << "Detected " << objectsDetected << " objects:" << endl;
    
                for (int i = 0; i < objectsDetected; ++i) {
                    float objectLat = latitude + static_cast<float>(rand() % 100) / 1000.0f;
                    float objectLon = longitude + static_cast<float>(rand() % 100) / 1000.0f;
                    cout << "Object " << i + 1 << " at (" << objectLat << ", " << objectLon << ")" << endl;
                }
                
                cout << endl;
            } catch (const exception& e) {
                cerr << "Error during scanning: " << e.what() << endl;
            }
        }
};

int main() {
    srand(time(NULL));
    
    ReconDrone rd(0.f, 0.f, 80.f, 60.f, 40.f, 10.f);
    
    rd.takeOff();
    rd.navigateTo(2.f, 3.f, 120.f);
    rd.scanArea(200.f);
    rd.land();

    return 0;
}
