#include <iostream>
#include <algorithm>

using namespace std;

class Medicine {
    string name, formula, manufactureDate, expirationDate;
    int retailPrice;
    
public : 
    Medicine(string name, string formula, string manufactureDate, string expirationDate, int retailPrice) : name(name), formula(formula), manufactureDate(manufactureDate), expirationDate(expirationDate), retailPrice(retailPrice) {}
    
    void setName(string name) {
        this->name = name;
    }
    
    void setFormula(string formula) {
        this->formula = formula;
    }
    
    void setManufactureDate(string manufactureDate) {
        this->manufactureDate = manufactureDate;
    }
    
    void setExpirationDate(string expirationDate) {
        this->expirationDate = expirationDate;
    }
    
    void setRetailPrice(int retailPrice) {
        this->retailPrice = retailPrice;
    }
    
    string getName() const {
        return name;
    }
    
    string getFormula() const {
        return formula;
    }
    
    string getManufactureDate() const {
        return manufactureDate;
    }
    
    string getExpirationDate() const {
        return expirationDate;
    }
    
    int getRetailPrice() const {
        return retailPrice;
    }
    
    virtual void printDetails() {
        cout << "Name : " << name << endl << "Formula : " << formula << endl << "Manufacture Date : " << manufactureDate << endl << "Expiration Date : " << expirationDate << endl << "Retail price : " << retailPrice << endl;
    }
};

class Tablet : public Medicine {
    int sucroseLevel;
    
public :
    Tablet(string name, string formula, string manufactureDate, string expirationDate, int retailPrice, int sucroseLevel) : Medicine(name, formula, manufactureDate, expirationDate, retailPrice), sucroseLevel(sucroseLevel) {}
    
    void printDetails() {
        Medicine::printDetails();
        cout << "Sucrose Level : " << sucroseLevel << endl;
    }
};

class Capsule : public Medicine {
    float absorptionPercentage;
    
public :
    Capsule(string name, string formula, string manufactureDate, string expirationDate, int retailPrice, float absorptionPercentage) : Medicine(name, formula, manufactureDate, expirationDate, retailPrice), absorptionPercentage(absorptionPercentage) {}
    
    void printDetails() {
        Medicine::printDetails();
        cout << "Absorption Percentage : " << absorptionPercentage << endl;
    }
};

class Syrup : public Medicine {
    Syrup(string name, string formula, string manufactureDate, string expirationDate, int retailPrice) : Medicine(name, formula, manufactureDate, expirationDate, retailPrice) {}
    
    void printDetails() {
        Medicine::printDetails();
    }
};

class Pharmacist {
public :
    void searchMedicine(Medicine medicines[], int totalMedicines, Medicine medicine) {
        for(int i = 0; i < totalMedicines; i++) {
            if(medicines[i].getFormula() == medicine.getFormula()) {
                medicines[i].printDetails();
            }
        }
    }
};

class Counter {
public :
    void searchMedicine(Medicine medicines[], int totalMedicines, Medicine medicine) {
        for(int i = 0; i < totalMedicines; i++) {
            if(medicines[i].getName() == medicine.getName()) {
                medicines[i].printDetails();
            }
        }
    }
};

int main() {

    return 0;
}
