#include <iostream>
using namespace std;

class DarazPersonData {
    string firstName, lastName, address, city, state, zip, phone;
    
    public :
        void setFirstName(string firstName) {
            this->firstName = firstName;
        }
        
        void setLastName(string lastName) {
            this->lastName = lastName;
        }
        
        void setAddress(string address) {
            this->address = address;
        }
        
        void setCity(string city) {
            this->city = city;
        }
        
        void setState(string state) {
            this->state = state;
        }
        
        void setZip(string zip) {
            this->zip = zip;
        }
        
        void setPhone(string phone) {
            this->phone = phone;
        }
        
        string getFirstName() const {
            return firstName;
        }
        
        string getLastName() const {
            return lastName;
        }
        
        string getAddress() const {
            return address;
        }
        
        string getCity() const {
            return city;
        }
        
        string getState() const {
            return state;
        }
        
        string getZip() const {
            return zip;
        }
        
        string getPhone() const {
            return phone;
        }
};

class DarazCustomerData : public DarazPersonData {
    int customerNumber, loyaltyPoints;
    
    public :
        void setCustomerNumber(int customerNumber) {
            if(customerNumber < 0) cout << "Invalid customer number" << endl;
            else this->customerNumber = customerNumber;
        }
        
        void setLoyaltyPoints(int loyaltyPoints) {
            if(loyaltyPoints < 0) cout << "Invalid loyalty points" << endl;
            else this->loyaltyPoints = loyaltyPoints;
        }
        
        int getCustomerNumber() const {
            return customerNumber;
        }
        
        int getLoyaltyPoints() const {
            return loyaltyPoints;
        }
};

class DarazLoyaltyProgram : public DarazCustomerData {
    public :
        void addLoyaltyPoints(int purchase) {
            if(purchase > 1000 && purchase <= 2000) setLoyaltyPoints(getLoyaltyPoints() + 20);
            else if(purchase > 2000 && purchase <= 3000) setLoyaltyPoints(getLoyaltyPoints() + 40);
            else if(purchase > 3000 && purchase <= 4000) setLoyaltyPoints(getLoyaltyPoints() + 60);
            else if(purchase > 4000 && purchase <= 5000) setLoyaltyPoints(getLoyaltyPoints() + 80);
            else if(purchase > 5000) setLoyaltyPoints(getLoyaltyPoints() + 100);
        }
        
        void redeemLoyaltyPoints(int discount) {
            int currentLoyaltyPoints = getLoyaltyPoints();
            
            if(discount > 1000 && discount <= 2000 && currentLoyaltyPoints >= 20) setLoyaltyPoints(currentLoyaltyPoints - 20);
            else if(discount > 2000 && discount <= 3000 && currentLoyaltyPoints >= 40) setLoyaltyPoints(currentLoyaltyPoints - 40);
            else if(discount > 3000 && discount <= 4000 && currentLoyaltyPoints >= 60) setLoyaltyPoints(currentLoyaltyPoints - 60);
            else if(discount > 4000 && discount <= 5000 && currentLoyaltyPoints >= 80) setLoyaltyPoints(currentLoyaltyPoints - 80);
            else if(discount > 5000 && currentLoyaltyPoints >= 100) setLoyaltyPoints(currentLoyaltyPoints - 100);
        }
        
        void displayLoyaltyPoints() {
            cout << "Loyalty Points : " << getLoyaltyPoints() << endl;
        }
};

int main() {
    
    DarazLoyaltyProgram customer;
    
    customer.setFirstName("Muhammad"), customer.setLastName("Umar"), customer.setAddress("D-544, Block J, Gulshan"), customer.setCity("Karachi"), customer.setState("Sindh"), customer.setZip("1335"), customer.setPhone("0354768945");

    customer.setCustomerNumber(3000), customer.setLoyaltyPoints(50);
    
    cout << "Customer's data" << endl << "First Name : " << customer.getFirstName() << endl << "Last Name : " << customer.getLastName() << endl << "Address : " << customer.getAddress() << endl << "City : " << customer.getCity() << endl << "State : " << customer.getState() << endl << "Zip : " << customer.getZip() << endl << "Phone : " << customer.getPhone() << endl;

    cout << endl << "Customer number : " << customer.getCustomerNumber() << endl << "Loyalty Points : " << customer.getLoyaltyPoints() << endl;
    
    customer.addLoyaltyPoints(3000);
    
    cout << endl << "After doing purchase of 3000" << endl;
    customer.displayLoyaltyPoints();
    
    customer.redeemLoyaltyPoints(4000);
    
    cout << endl << "After getting discount 0f 4000" << endl;
    customer.displayLoyaltyPoints();

    return 0;
}
