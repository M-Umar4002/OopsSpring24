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
            cin >> name;
            
            cout << "Enter health status : ";
            cin >> healthStatus;
            
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
        Adopter() {}
    
        Adopter(string name, int mobNum) : adopterName(name), adopterMobileNum(mobNum) {}
        
        void adoptPet(Pet pet) {
            adoptedPetRecords.push_back(pet);
        }
        
        bool returnPet(string name) {
            for(int i = 0; i < adoptedPetRecords.size(); i++) {
                if(adoptedPetRecords[i].getName() == name) {
                    adoptedPetRecords.erase(adoptedPetRecords.begin()+i);
                    cout << "Returned pet succesfully" << endl;
                    return true;
                }
            }
            cout << "Pet having name " << name << " not found" << endl;
            return false;
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

void adoptPet(vector<Pet> pets, int &totalPets, Adopter adopter) {
    string name;
    
    cout << endl << "Enter pet name you want to adopt : ";
    cin >> name;
    
    for(int i = 0; i < totalPets; i++) {
        if(pets[i].getName() == name) {
            string adopterName;
            int mobNum;
            
            cout << "Enter name of adopter : ";
            cin.ignore();
            getline(cin, adopterName);
            
            cout << "Enter mobile number : ";
            cin >> mobNum;
            
            adopter = Adopter(adopterName, mobNum);
            adopter.adoptPet(pets[i]);
            pets.erase(pets.begin() + i);
            
            totalPets--;
            
            cout << endl << "Pet adopted successfully" << endl;
            return;
        }
    }
    
    cout << "Pet having name " << name << "not found" << endl;
}

void interactWithPet(vector<Pet> pets, int totalPets) {
    
    string name;
    
    cout << "Enter name of pet you want to interact with : ";
    cin >> name;
    
    for(Pet pet : pets) {
        if(pet.getName() == name) {
            int happinessLevel, hungerLevel;
            string healthStatus;
            
            cout << "Enter new happiness level of the pet (1-10) : ";
            cin >> happinessLevel;
            
            cout << "Enter new health status of the pet : ";
            cin >> healthStatus;
            
            cout << "Enter new hunger level of the pet (1-10) : ";
            cin >> hungerLevel;
            
            pet.updateHappiness(happinessLevel), pet.updateHealth(healthStatus), pet.updateHunger(hungerLevel);
            return;
        }
    }
    cout << "Pet having name" << name << " not found" << endl;
}

bool returnPet(Adopter adopter) {
    string name;

    cout << "Enter name of pet : ";
    cin >> name;
    
    return adopter.returnPet(name);
}

int main() {

    vector<Pet> pets;
    
    int totalPets = 0;
    
    while(true) {
        menu();
        int choice;
        cout << "Choice : ";
        cin >> choice;
        
        Adopter adopter;
        
        switch(choice) {
            case 1 : 
                pets.push_back(addPet());
                totalPets++;
                break;
            case 2 : 
                displayAllPets(pets, totalPets);
                break;
            case 3 : 
                adoptPet(pets, totalPets, adopter);
                break;
            case 4 : 
                adopter.displayAdoptedPets();
                break;
            case 5 :
                interactWithPet(pets, totalPets);
                break;
            case 6 : 
                if(returnPet(adopter)) totalPets++;
                break;
            case 7 : 
                return 0;
            default :
                cout << "Incorrect choice" << endl;
        }
        
        cout << endl;
    }
}
