#include <iostream>

using namespace std;

class Medicine {
    string name, formula, manufactureDate, expirationDate;
    int retailPrice;
    
    public : 
        Medicine(string name, string formula, string manufactureDate, string expirationDate, int retailPrice) : name(name), formula(formula), manufactureDate(manufactureDate), expirationDate(expirationDate), retailPrice(retailPrice) {}
        
        void setName(string name) const;
        void setFormula(string formula) const;
        void setManufactureDate(string manufactureDate) const;
        void setExpirationDate(string expirationDate) const;
        void setRetailPrice(int retailPrice) const;
        
        string getName() const;
        string getFormula() const;
        string getManufactureDate() const;
        string getExpirationDate() const;
        int getRetailPrice() const;
        
        virtual void printDetails() {}
        
        bool operator==(const Medicine &med2) {
            return this->expirationDate.substr(6, 4) == med2.expirationDate.substr(6, 4);
        }
};

class Tablet : public Medicine {
    float sucroseLevel;
    
    public :
        Tablet(string name, string formula, string manufactureDate, string expirationDate, int retailPrice, float sucroseLevel) : Medicine(name, formula, manufactureDate, expirationDate, retailPrice), sucroseLevel(sucroseLevel) {}
        
        void printDetails() {}
};

class Capsule : public Medicine {
    float absorptionPercentage;
    
    public :
        Capsule(string name, string formula, string manufactureDate, string expirationDate, int retailPrice, float absorptionPercentage) : Medicine(name, formula, manufactureDate, expirationDate, retailPrice), absorptionPercentage(absorptionPercentage) {}
        
        void printDetails() {}
};

class Syrup : public Medicine {
    public :
        Syrup(string name, string formula, string manufactureDate, string expirationDate, int retailPrice) : Medicine(name, formula, manufactureDate, expirationDate, retailPrice) {}
        
        void printDetails() {}
};

class Pharmacist {
    public :
        void searchMedicine(Medicine medicines[], int totalMedicines, Medicine medicine);
};

class Counter {
    static float revenue;
    
    public :
        void searchMedicine(Medicine medicines[], int totalMedicines, Medicine medicine);
        
        void updateRevenue(float amount);
};

int main() {
    Tablet tablet("Panadol", "HGFT3", "10/10/2023", "09/09/2024", 10, 0.3);
    
    Capsule capsule("Omeprazole", "JUFG53", "08/08/2022", "09/09/2024", 10, 60.87);
    
    Syrup syrup("Omeprazole", "JUFG53", "04/04/2024", "02/02/2025", 10);
    
    tablet == capsule ? cout << "Both tablet and cabsule will expire in same year\n" : cout << "Both tablet and cabsule will not expire in same years\n";
    
    tablet == syrup ? cout << "Both tablet and syrup will expire in same year\n" : cout << "Both tablet and syrup will not expire in same years\n";

    return 0;
}
