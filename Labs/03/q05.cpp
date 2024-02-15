#include <iostream>
using namespace std;

class StationaryShop {
    string items[100];
    float prices[100];
    static int counter;

    public:
        void addItemsAndPrices() {
            int totalItems;
            cout << endl << "Enter number of items you want to add : ";
            cin >> totalItems;
            
            for(int i = counter; i < counter + totalItems; i++) {
                cout << endl << "Enter details of item " << i+1 << endl;
                
                cout << "Enter item's name : ";
                cin.ignore();
                getline(cin, items[i]);
                
                cout << "Enter item's price : ";
                cin >> prices[i];
            }
            
            counter += totalItems;
        }
        
        void retrieveItems() {
            for(int i = 0; i < counter; i++) {
                if(!i) cout << endl << "List of items" << endl;
                cout << "Item " << i+1 << " : " << items[i] << endl;
            }
        }
        
        void modifyPrice(int itemNo, float price) {
            prices[itemNo-1] = price;
        }
        
        void displayItemsAndPrices() {
            for(int i = 0; i < counter; i++) {
                cout << endl << "Details of item " << i+1 << endl << "Item's Name : " << items[i] << endl << "Item's price : " << prices[i] << endl;;
            }
        }
        
        void generateReciept() {
            int totalItemsToBuy;
            
            cout << endl << "Enter number of distinct items you want to buy from " << counter << " items : ";
            cin >> totalItemsToBuy;
            
            int indexes[totalItemsToBuy], quantity[totalItemsToBuy];
            
            for(int i = 0; i < totalItemsToBuy; i++) {
                cout << endl << "Enter no. of no. " << i+1 << " item you want to buy : ";
                cin >> indexes[i];
                
                indexes[i]--;
                
                cout << "Enter its quantity : ";
                cin >> quantity[i];
            }
            
            int totalPrice = 0;
            
            for(int i = 0; i < totalItemsToBuy; i++) {
                if(!i) cout << endl << endl << "Reciept : " << endl << "---------" << endl << endl << "    Name\t|\tPrice\t   |\tQuantity" << endl << "\t\t|\t\t   |" << endl;
                cout << "   " << items[indexes[i]] << "\t|\t " << prices[indexes[i]] << "\t   |\t   " << quantity[i] << endl;
                totalPrice += prices[indexes[i]] * quantity[i];
            }
            
            cout << endl << "Total Price : " << totalPrice << endl;
        }
};

int StationaryShop :: counter = 0;

void menu() {
    cout << "Choose any option from following" << endl << "\t1. Add items and their prices" << endl << "\t2. Retrieve the list of items" << endl << "\t3. Modify the prices of items" << endl << "\t4. Display all items with their prices" << endl << "\t5. Generate Reciept" << endl << "\t6. Exit" << endl;
}

void modifyPrice(StationaryShop &shop) {
    int itemNo;
    float newPrice;

    cout << endl << "Enter itemNo. for which you want to modify the price : ";
    cin >> itemNo;

    cout << "Enter the new price : ";
    cin >> newPrice;

    shop.modifyPrice(itemNo, newPrice);
}

int main(){
    
    StationaryShop shop;
    
    while(true) {
        menu();
        int choice;
        cout << "Choice : ";
        cin >> choice;
        
        switch(choice) {
            case 1 : 
                shop.addItemsAndPrices();
                break;
            case 2 :
                shop.retrieveItems();
                break;
            case 3 :
                modifyPrice(shop);
                break;
            case 4 : 
                shop.displayItemsAndPrices();
                break;
            case 5 : 
                shop.generateReciept();
                break;
            default : 
                return 0;
        }
        
        cout << endl;
    }
}
