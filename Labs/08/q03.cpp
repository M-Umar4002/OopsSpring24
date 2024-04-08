#include <iostream>
using namespace std;

class Position {
    double x, y, z;
    
    public : 
        Position(double x, double y, double z) : x(x), y(y), z(z) {}
        
        void setX(double x) {
            this->x = x;
        }
        
        void setY(double y) {
            this->y = y;
        }
        
        void setZ(double z) {
            this->z = z;
        }
        
        double getX() const {
            return x;
        }
        
        double getY() const {
            return y;
        }
        
        double getZ() const {
            return z;
        }
};

class Health {
    int health;
    
    public : 
        Health(int health) : health(health) {}
        
        void setHealth(int health) {
            this->health = health;
        }
        
        int getHealth() const {
            return health;
        }
};

class Character : public Position, public Health {
    string name;
    int id;
    
    public :
        Character(string name, int id) : Position(0.0, 0.0, 0.0), Health(100), name(name), id(id) {}
        
        void move(double moveInX, double moveInY, double moveInZ) {
            setX(getX() + moveInX), setY(getY() + moveInY), setZ(getZ() + moveInZ);
        }
        
        void decreaseHealth(int decrease) {
            if(getHealth() - decrease <= 0) {
                setHealth(0);
                cout << "Player lose the game" << endl;
            } else setHealth(getHealth() - decrease);
        }
        
        void displayDetails() {
            cout << "Name : " << name << endl << "Id : " << id << endl << "Health : " << getHealth() << endl << "Position" << endl << "On x : " << getX() << endl << "On y : " << getY() << endl << "On z : " << getZ() << endl;
        }
};

int main() {
    
    Character c("Character1", 1);
    
    cout << "On creating object" << endl<< endl;
    c.displayDetails();
    
    c.move(1.5, -3.3, 4.8), c.decreaseHealth(34);
    
    cout << endl << "After using the other functions" << endl<< endl;
    c.displayDetails();
    
    return 0;
}
