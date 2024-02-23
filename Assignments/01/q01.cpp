#include <iostream>
#include <array>
#include <vector>
using namespace std;

class Pet {
    string healthStatus, name;
    int hungerLevel, happinessLevel;
    vector<string> specialSkills;
    
    public : 
        void addPet() {
            cout << "Enter pet's name : ";
            cin >> name;
            
            cout << "Enter health status : ";
            cin >> healthStatus;
            
            cout << "Enter hunger level : ";
            cin >> hungerLevel;
            
            cout << "Enter happiness level : ";
            cin >> happinessLevel;
            
            int size;
            
            cout << "Enter total number of skills : ";
            cin >> size;
            
            for(int i = 0; i < size; i++) {
                cout << "Enter skill " << i+1 << " : ";
                cin >> specialSkills[i];
            }
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
                happinessLevel--;
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
        
        string getName() {
            return name;
        }
};

void menu() {
    cout << "Choose any option from following" << endl << "\t1. Add pet" << endl << "\t2. Display all pets" << endl << "\t3. Adopt pet" << endl << "\t4. Display all adopteed pets" << endl << "\t5. Return pet" << endl << "\t6. Exit" << endl;
}

Pet addPet() {
    Pet pet;
    
    cout << endl << "Enter details of pet : " << endl;
    pet.addPet();
    
    return pet;
}

void displayAllPets(Pet pets[], int totalPets) {
    for(int i = 0; i < totalPets; i++) {
        cout << "Details of pet " << i+1 << endl;
        pets[i].displayPetDetails();
        cout << endl;
    }
}

void adopPet(Pet pets[], int totalPets) {
    string name;
    
    cout << "Enter pet name you want to adopt : ";
    cin >> name;
    
    for(int i = 0; i < totalPets; i++) {
        if(pets[i].getName() == name)
    }
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
                pets[totalPets++] = addPet();
                break;
            case 2 : 
                displayAllPets(pets, totalPets);
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
