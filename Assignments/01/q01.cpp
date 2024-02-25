#include <iostream>
#include <vector>
using namespace std;

class Pet {
    string healthStatus, name;
    int hungerLevel, happinessLevel;
    vector<string> specialSkills;
    
    public : 
        void addPet() {
            cout << "Enter pet's name : ";
            cin.ignore();
            getline(cin, name);
            
            cout << "Enter health status : ";
            getline(cin, healthStatus);
            
            cout << "Enter hunger level (1-10) : ";
            cin >> hungerLevel;
            
            cout << "Enter happiness level (1-10) : ";
            cin >> happinessLevel;
            
            int size;
            
            cout << "Enter total number of skills : ";
            cin >> size;
            
            for(int i = 0; i < size; i++) {
                string skill;
                cout << "Enter skill " << i+1 << " : ";
                cin >> skill;
                specialSkills.push_back(skill);
            }
        }
    
        void displayPetDetails() {
            cout << "Name : " << name << endl << "Health status : " << healthStatus << endl << "Happiness level : " << happinessLevel << endl << "Hunger level : " << hungerLevel << endl;
            
            for(int i = 0; i < specialSkills.size(); i++) {
                if(!i) cout << "Special skills are : ";
                cout << specialSkills[i];
                i != specialSkills.size()-1 ? cout << ", " : cout << endl;
            }
        }

        
        void updateHappiness(int hap) {
            happinessLevel = hap;
        }
        
        void updateHealth(string health) {
            healthStatus = health;
        }
        
        void updateHunger(int hunger) {
            hungerLevel = hunger;
            
            if(hungerLevel >= 5 && happinessLevel > 0) {
                happinessLevel--;
            } else if(hungerLevel < 5 && happinessLevel < 10) {
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
        
        void adoptPet(Pet &pet) {
            adoptedPetRecords.push_back(pet);
        }
        
        int returnPet(string name) {
            for(int i = 0; i < adoptedPetRecords.size(); i++) {
                if(adoptedPetRecords[i].getName() == name) {
                    return i;
                }
            }
            cout << "Pet having name " << name << " not found" << endl;
            return -1;
        }
        
        void displayAdoptedPets() {
            for(Pet pet : adoptedPetRecords) {
                cout << endl;
                pet.displayPetDetails();
                cout << endl;
            }
        }
        
        vector<Pet>& getAdoptedPetRecords() {
            return adoptedPetRecords;
        }
};

void menu() {
    cout << "Choose any option from following" << endl << "\t1. Add pet" << endl << "\t2. Display all pets" << endl << "\t3. Adopt pet" << endl << "\t4. Display all adopteed pets" << endl << "\t5. Interact with pet" << endl << "\t6. Return pet" << endl << "\t7. Exit" << endl;
}

Pet addPet() {
    Pet pet;
    
    cout << endl << "Enter details of pet" << endl;
    pet.addPet();
    
    return pet;
}

void displayAllPets(vector<Pet> pets, int totalPets) {
    for(int i = 0; i < totalPets; i++) {
        cout << endl << "Details of pet " << i+1 << endl;
        pets[i].displayPetDetails();
        cout << endl;
    }
}

void adoptAnyPet(vector<Pet> &pets, int &totalPets, Adopter &adopter) {
    string name;
    
    cout << endl << "Enter pet name you want to adopt : ";
    cin.ignore();
    getline(cin, name);
    
    for(int i = 0; i < totalPets; i++) {
        if(pets[i].getName() == name) {
            adopter.adoptPet(pets[i]);
            pets.erase(pets.begin() + i);
            
            totalPets--;
            
            cout << endl << "Pet adopted successfully" << endl;
            return;
        }
    }
    
    cout << "Pet having name " << name << "not found" << endl;
}

bool interact(vector<Pet> &pets, string name) {
    for(Pet &pet : pets) {
        if(pet.getName() == name) {
            int happinessLevel, hungerLevel;
            string healthStatus;
            
            cout << "Enter new happiness level of the pet (1-10) : ";
            cin >> happinessLevel;
            
            cout << "Enter new health status of the pet : ";
            cin.ignore();
            getline(cin, healthStatus);
            
            cout << "Enter new hunger level of the pet (1-10) : ";
            cin >> hungerLevel;
            
            pet.updateHappiness(happinessLevel), pet.updateHealth(healthStatus), pet.updateHunger(hungerLevel);
            return true;
        }
    }
    return false;
}

void interactWithPet(vector<Pet> &pets, Adopter &adopter, int totalPets) {
    
    string name;
    
    cout << endl << "Enter name of pet you want to interact with : ";
    cin.ignore();
    getline(cin, name);
    
    if(interact(pets, name)) return;
    
    vector<Pet> &adoptedPetRecords = adopter.getAdoptedPetRecords();
    
    if(interact(adoptedPetRecords, name)) return;

    cout << endl << "Pet having name" << name << " not found" << endl;
}

bool returnAPet(vector<Pet> &pets, Adopter &adopter) {
    string name;

    cout << endl << "Enter name of pet : ";
    cin.ignore();
    getline(cin, name);
    
    int i = adopter.returnPet(name);
    
    if(i != -1) {
        pets.push_back(adopter.getAdoptedPetRecords().at(i));
        adopter.getAdoptedPetRecords().erase(adopter.getAdoptedPetRecords().begin() + i);
        cout << endl << "Returned pet succesfully" << endl;
        return true;
    }
    
    return false;
}

int main() {

    vector<Pet> pets;
    
    int totalPets = 0;
    
    Adopter adopter("Ali", 54);
    
    while(true) {
        menu();
        int choice;
        cout << "Choice : ";
        cin >> choice;
    
        switch(choice) {
            case 1 : 
                pets.push_back(addPet());
                totalPets++;
                break;
            case 2 : 
                displayAllPets(pets, totalPets);
                break;
            case 3 : 
                adoptAnyPet(pets, totalPets, adopter);
                break;
            case 4 : 
                adopter.displayAdoptedPets();
                break;
            case 5 :
                interactWithPet(pets, adopter, totalPets);
                break;
            case 6 : 
                if(returnAPet(pets, adopter)) totalPets++;
                break;
            case 7 : 
                return 0;
            default :
                cout << "Incorrect choice" << endl;
        }
        cout << endl;
    }
}
