#include <iostream>
using namespace std;

class Engine {
    string model;
    int horsePower;
    
    public :
        Engine(string mod, int hp) : model(mod) , horsePower(hp) {}
        
        string getModel() const {
            return model;
        }
        
        int getHorsePower() const {
            return horsePower;
        }
};

class Wheels {
    float size;
    string material;
    
    public :
        Wheels(float size, string mat) : material(mat) {
            this->size = size;
        }
        
        float getSize() const {
            return size;
        }
        
        string getMaterial() const {
            return material;
        }
};

class HeadLight {
    int brightness;
    string lightSource;
    
    public :
        HeadLight() {}
        HeadLight(int bright, string source) : brightness(bright), lightSource(source) {}
        
        int getBrightness() const {
            return brightness;
        }
        
        string getSource() const {
            return lightSource;
        }
};

class Steering {
    string type;
    float turningRadius;
    
    public :
        Steering(string t, float radius) : type(t), turningRadius(radius) {}
        
        string getType() const {
            return type;
        }
        
        float getTurningRadius() const {
            return turningRadius;
        }
};

class Car {
    Engine engine;
    Wheels wheels[4];
    HeadLight* lights[4];
    Steering* steer;
    string name;
    int model;
    
    public :
        Car(string n, int mod, HeadLight lights[4], Steering* steer) : name(n), model(mod), engine("Electric engine", 576), wheels{Wheels(20, "Steel"), Wheels(20, "Steel"), Wheels(30, "Alloy"), Wheels(30, "Alloy")} {
            for(int i = 0; i < 4; i++) {
                this->lights[i] = &lights[i];
            }
            this->steer = steer;
        }
        
        void setLights(HeadLight lights[4]) {
            for(int i = 0; i < 4; i++) {
                this->lights[i] = &lights[i];
            }
        }
        
        void setSteering(Steering* steer) {
            this->steer = steer;
        }
        
        void display() {
            cout << "Car Name : " << name << endl << "Car Model : " << model << endl << "Engine Model : " << engine.getModel() << endl << "Engine horsepower : " << engine.getHorsePower() << endl << "Steering type : " << steer->getType() << endl << "Steering turning radius : " << steer->getTurningRadius() << endl << endl << "Details of wheels" << endl << endl;
            
            for(int i = 0; i < 4; i++) cout << "Wheel " << i+1 << endl << "Size : " << wheels[i].getSize() << endl << "Material : " << wheels[i].getMaterial() << endl << endl;
        
            cout << "Details of head Lights " << endl << endl;
            
            for(int i = 0; i < 4; i++) cout << "Head Light " << i+1 << endl << "Brightness : " << lights[i]->getBrightness() << endl << "Light Source : " << lights[i]->getSource() << endl << endl;
        }
};

int main() {
    
    HeadLight lights[4] = {HeadLight(50, "LED"), HeadLight(50, "LED"), HeadLight(80, "HID"), HeadLight(80, "HID")};
    Steering steer("Power Steering", 7);
    
    Car car("Toyota Corolla", 2020, lights, &steer);
    car.display();

    return 0;
}
