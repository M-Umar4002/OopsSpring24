#include <iostream>
using namespace std;

class Restaurant {
    string name, location, menuList[15];
    float priceList[15];
    int validCouponCodesList[15];
    static int couponsRedeemedCount;
    
    public : 
    
        Restaurant(string rname, string loc) : name(rname), location(loc) {}
        
        int totalMenu;
        
        void setMenuAndPriceList() {
            cout << "Enter total number of menu : ";
            cin >> totalMenu;
            
            for(int i = 0; i < totalMenu; i++) {
                cout << "Enter details of menu " << i+1 << endl << "Enter name : ";
                cin >> menuList[i];

                cout << "Enter price : ";
                cin >> priceList[i];
            }
        }
        
        void displayMenu() {

            
            for(int i = 0; i < totalMenu; i++) {

                cout << "Menu " << i+1 << " : " << menuList[i] << endl;
            }
        }
        
        float generateBill() {
            return 1;
        }
        
        float applyDiscount() {
            return 1;
        }
};

class BOGOCoupon {
    string couponCode, validFrom, validUntil, restaurantCode;
    
    private : 
        bool isValid() {
            
        }
};

class User {
    string name, couponsList[15];
    int age, mobileNumber;
    
    private : 
        void accumulateCoupon() {
            
        }
        
        bool hasValidCoupon() {
            
        }
        
        bool redeemCoupon() {
            
        }
};

int main() {
    
    Restaurant r1("Food Haven", "City Center"), r2("Pixel Bites", "Cyber street");



    return 0;
}
