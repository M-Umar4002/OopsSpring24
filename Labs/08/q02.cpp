#include <iostream>
using namespace std;

class Character {
    int health, damage;
    
    public :
        Character(int health, int damage) : health(health), damage(damage) {}
        
        void dispaly() {
            cout << "Health : " << health << endl << "Damage : " << damage << endl;
        }
};

class Enemy : public Character {
    public : 
        Enemy(int health, int damage) : Character(health, damage) {}
        
        void dispaly() {
            Character::dispaly();
        }
};

class Player : public Character {
    public : 
        Player(int health, int damage) : Character(health, damage) {}
        
        void dispaly() {
            Character::dispaly();
        }
};

class Wizard : public Player {
    int magicPower;
    string spells;
    
    public : 
        Wizard(int health, int damage, int magicPower, string spells) : Player(health, damage), magicPower(magicPower), spells(spells) {}
        
        void dispaly() {
            Player::dispaly();
            cout << "Magic Power : " << magicPower << endl << "Spells : " << spells << endl;
        }
};

int main() {
    Wizard wizard(80, 20, 60, "Shield");
    wizard.dispaly();
    
    return 0;
}
