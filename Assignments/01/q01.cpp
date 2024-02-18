/*
* Name: Muhammad Umar
* Roll No: 23K-0023
*/

#include <iostream>
#include <array>
using namespace std;

class Book {
    string healthStatus;
    int hungerLevel, happinessLevel;
    array<string, 3> specialSkills;
    
    public : 
        void displayPetDetails() {
            cout << "Health status : " << healthStatus << endl << "Happiness level : " << happinessLevel << endl << "Hunger level : " << hungerLevel << endl;
            
            for(int i = 0; i < specialSkills.size(); i++) {
                if(!i) cout<< endl << "Special skills are" << endl;
                cout << specialSkills[i] << endl;
            }
        }
        
        void updateHappiness(int hap) {
            happinessLevel = hap;
        }
        
        void updateHealth(int health) {
            healthStatus = health;
        }
        
        void updateHunger(int hunger) {
            hungerLevel = hunger;
        }
};

class Adopter {
    string adopterName;
    int adopterMobileNum;
    
    public : 
        Adopter(string name, mobNum) : adopterName(name), adopterMobileNum(mobNum) {}
};

int main() {

    

    return 0;
}
