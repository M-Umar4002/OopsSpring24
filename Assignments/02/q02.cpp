#include <iostream>
#include <vector>
using namespace std;

class Player {
    int id, health;
    string name;
    
    public :
        Player(int id, string name) : id(id), name(name), health(100) {}
        
        void setHealth(int health) {
            this->health = health;
        }
        
        int getHealth() const {
            return health;
        }
};

class Weapon {
    vector<string> weapons;
    
    public : 
        Weapon(vector<string> weap) : weapons(weap) {
            string defaultWeapons[] = {"Pistol", "Shotgun", "Assault Rifle", "Sniper Rifle", "Submachine Gun (SMG)", "Rocket Launcher", "Grenade", "Knife", "Handgun", "Machine Gun"};
            
            size_t totalWeapons = weapons.size();
            
            if(totalWeapons < 5) {
                for(int i = 0, j = 0; i < 5 - totalWeapons; i++, j++) {
                    string weap = defaultWeapons[j];
                    
                    bool inList = false;
                    
                    for(int k = 0; k < weapons.size(); k++) {
                        if(weap == weapons[k]) {
                            inList = true;
                            i--;
                            break;
                        }
                    }
                    
                    if(!inList) weapons.push_back(weap);
                }
            }
        }
        
        string use() {
            for(int i = 0; i < weapons.size(); i++) {
                if(!i) cout << "Choose any weapon from following to use : " << endl;
                cout << i+1 << ". " << weapons[i] << endl;
            }
            
            int choice;
            
            cout << "Enter weapon number you want to use : ";
            cin >> choice;
            
            return weapons[choice-1];
        }
};

class Enemy;

class Character : public Player, public Weapon {
    int level, points;
    string experience;
    
    public :
        Character(int id, string name, vector<string> weap, int level = 0, int points = 0, string experience = "Beginner") : Player(id, name), Weapon(weap), level(level), points(points), experience(experience) {}
        
        string getExperience() const {
            return experience;
        }
        
        void levelUp() {
            level++;
            
            experience == "Beginner" ? experience = "Intermediate" : experience == "Intermediate" ? experience = "Advanced" : experience = "Expert";
        }
        
        void playGame(Enemy &enemy);
};

class Enemy : public Player, public Weapon {
    int damage;
    
    public : 
        Enemy(int id, string name, int damage, vector<string> weap) : Player(id, name), Weapon(weap) {
            damage < 1 ? this->damage = 1 : damage > 10 ? this->damage = damage : this->damage = damage;
        }
        
        void attack(Character &character) {
            cout << "Enemy!" << endl;
            
            string weapon = use();
    
            cout << endl << "Enemy uses " << weapon << " to attck the character" << endl << endl;
            
            character.setHealth(character.getHealth() - damage);
        }
};

void Character :: playGame(Enemy &enemy) {
    cout << "Character!" << endl;
    
    string weapon = use();
    
    cout << endl << "Character uses " << weapon << " to attack the enemy" << endl << endl;
    
    enemy.setHealth(enemy.getHealth() - 5);
    
    points += 10;
    
    levelUp();
}

int main() {
    
    Character character(202, "John", {"Handgun", "Machine Gun", "Knife", "Sniper Rifle", "Rocket Launcher", "Grenade"});
    
    Enemy enemy(420, "Bot", 6, {"Knife", "Sniper Rifle"});
    
    cout << "Character's health : " << character.getHealth() << endl << "Character's experience : " << character.getExperience() << endl;
    cout << "Enemy's health : " << enemy.getHealth() << endl;
    
    for(int i = 0; i  < 3; i++) {
        cout << endl << "Round " << i+1 << endl << endl;
        
        character.playGame(enemy), enemy.attack(character);
        
        cout << "Character's health : " << character.getHealth() << endl << "Character's experience : " << character.getExperience() << endl;
        cout << "Enemy's health : " << enemy.getHealth() << endl << endl;
    }

    return 0;
}
