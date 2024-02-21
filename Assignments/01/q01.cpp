#include <iostream>
#include <array>
#include <vector>
using namespace std;

class Pet {
    string healthStatus, name;
    int hungerLevel, happinessLevel;
    array<string, 3> specialSkills;
    
    public : 
        void setData(string n, string health, int hung, int hap) {
            
        }
    
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
            
            if(hungerLevel >= 5) {
                happinessLevel --;
            } else {
                happinessLevel++;
            }
        }
        
        string getName() {
            return name;
        }
};

class Adopter {
    string adopterName;
    int adopterMobileNum;
    vector<Pet> adoptedPetRecords;
    
    public : 
        Adopter(string name, int mobNum) : adopterName(name), adopterMobileNum(mobNum) {}
        
        void adoptPet(Pet pet) {
            adoptedPetRecords.push_back(pet);
        }
        
        void returnPet(string name) {
            for(int i = 0; i < adoptedPetRecords.size(); i++) {
                if(adoptedPetRecords[i].getName() == name) {
                    adoptedPetRecords.erase(adoptedPetRecords.begin()+i);
                }
            }
        }
        
        void displayAdoptedPets() {
            for(Pet pet : adoptedPetRecords) {
                cout << "Name : " << pet.getName() << endl;
                pet.displayPetDetails();
                cout << endl;
            }
        }
};

void menu() {
    cout << "Choose any option from following" << endl << "\t1. Add pet" << endl << "\t2. Display all pets" << endl << "\t3. Adopt pet" << endl << "\t4. Display all adopteed pets" << endl << "\t5. Return pet" << endl << "\t6. Exit" << endl;
}

void addPet() {
    
}

int main() {

    vector<Pet> pets;
    
    int totalPets = 0;
    
    while(true) {
        menu();
        int choice;
        cout << "Choice : ";
        cin >> choice;
        
        switch(choice) {
            case 1 : 
                cout << endl << "Enter details of pet : " << endl;
                
                break;
            case 2 : 
                break;
            case 3 : 
                break;
            case 4 : 
                break;
            case 5 : 
                break;
            case 6 :
            default :
                return 0;
        }
        
        cout << endl;
    }
}
