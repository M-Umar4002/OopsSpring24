/*
* Programmer: Muhammad Umar
* Roll no: 23K-0023
*/

#include <iostream>
#include <vector>
using namespace std;

class MenuItem {
    string foodName;
    int foodPrice;
    
    public :
        MenuItem(string fName, int fPrice) : foodName(fName), foodPrice(fPrice) {}
        
        string getFoodName() const {
            return foodName;
        }
        
        int getFoodPrice() const {
            return foodPrice;
        }
};

class Menu {
    vector<MenuItem> items;
    
    public : 
        void addItem() {
            string name;
            int price;
            
            cout << endl << "Enter food name : ";
            cin >> name;
            
            cout << "Enter price : ";
            cin >> price;
            
            items.push_back(MenuItem(name, price));
        }
        
        void removeItem() {
            string name;
            
            cout << endl << "Enter food name : ";
            cin >> name;
            
            for(int i = 0; i < items.size(); i++) {
                if(items[i].getFoodName() == name) {
                    items.erase(items.begin() + i);
                    cout << "Removed item successfully" << endl;
                    return;
                }
            }
            
            cout << "Item with name " << name << " does not exist" << endl;
        }
        
        void displayMenu() {
            for(int i = 0; i < items.size(); i++) cout << endl << "Details of menu " << i+1 << endl << "Food name : " << items[i].getFoodName() << endl << "Food price : " << items[i].getFoodPrice() << endl;
        }
        
        vector<MenuItem>& getItems() {
            return items;
        }
};

class Payment {
    static int totalMoney;
    
    public :
        void addMoney(int money) {
            totalMoney += money;
        }
        
        void displayTotalAmount() {
            cout << "Your total amount is : " << totalMoney << endl;
        }
};

int Payment :: totalMoney = 0;

class Order {
    vector<MenuItem> items;
    Payment pay;
    
    public :
        void order(Menu menu) {
            int totalItems;
            
            cout << endl << "Enter no. of items you want to buy : ";
            cin >> totalItems;
            
            for(int i = 0; i < totalItems; i++) {
                string name;
            
                cout << endl << "Enter name of food " << i+1 << " : ";
                cin >> name;
                
                vector<MenuItem> allItems = menu.getItems();
                
                int j;
                for(j = 0; j < allItems.size(); j++) {
                    if(name == allItems[j].getFoodName()) {
                        items.push_back(allItems[j]), pay.addMoney(allItems[j].getFoodPrice());
                        cout << endl << "Item with name " << name << " is added in order successfully" << endl << endl;
                        break;
                    }
                }
                
                if(j == allItems.size()) {
                    cout << endl << "Item having name " << name << " does not exist" << endl << endl;
                    i--;
                }
            }
            pay.displayTotalAmount();
        }
};

void showMenu() {
    cout << "Choose any option from following" << endl << "\t1. Add any item in menu" << endl << "\t2. Remove any item from menu" << endl << "\t3. Dispaly all items" << endl << "\t4. Place a order" << endl << "\t5. Exit" << endl;
}

int main() {
    Menu menu;
    
    while(true) {
        showMenu();
        int choice;
        cout << "Choice : ";
        cin >> choice;
        
        Order ord;
        
        switch(choice) {
            case 1 : 
                menu.addItem();
                break;
            case 2 : 
                menu.removeItem();
                break;
            case 3 : 
                menu.displayMenu();
                break;
            case 4 : 
                ord.order(menu);
                break;
            case 5 : 
                return 0;
            default :
                cout << "Incorrect choice" << endl;
        }
        cout << endl;
    }
}
