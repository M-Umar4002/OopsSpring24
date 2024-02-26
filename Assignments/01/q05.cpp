#include <iostream>
using namespace std;

class Restaurant {
    string name, location, menuList[3];
    float priceList[3];
    int validCouponCodesList[15];
    
    public : 
    
        static int couponsRedeemedCount;
    
        Restaurant(string rname, string loc) : name(rname), location(loc) {}
        
        void setMenuAndPriceList(string menu1, float price1, string menu2, float price2, string menu3, float price3) {
            menuList[0] = menu1, menuList[1] = menu2, menuList[2] = menu3, priceList[0] = price1, priceList[1] = price2, priceList[2] = price3;
        }
        
        void displayMenu() {
            for(int i = 0; i < 3; i++) {
                cout << "Dish " << i+1 << " : " << menuList[i] << "\t\tPrice : " << priceList[i] << endl;
            }
        }
        
        float generateBill() {
            return 1;
        }
        
        float applyDiscount() {
            return 1;
        }
};

int Restaurant :: couponsRedeemedCount = 0;

class BOGOCoupon {
    string couponCode, restaurantCode;
    int validFrom, validUntil;
    
    public : 
        BOGOCoupon() {};
        BOGOCoupon(string resCode, string cCode, int vFrom, int vUntil) {
            restaurantCode = resCode, couponCode = cCode, validFrom = vFrom, validUntil = vUntil;
        }

        bool isValid(int usedDate) {
            if(validFrom <= usedDate && validUntil >= usedDate) {
                return true;
            } else{
                cout << endl << "Coupon is not in its validity period" << endl;
                return false;
            }
        }
};

class User {
    string name, redeemCoupons[15];
    BOGOCoupon couponsList[15];
    int age, mobileNumber;
    int counter = Restaurant :: couponsRedeemedCount;
    
    public : 
        User(string n, int a, int mb) {
            name = n, age = a, mobileNumber = mb;
        }

        void accumulateCoupon() {
            string couponCode, restaurantCode;
            int validFrom, validUntil, usedDate;

            cout << endl << "Enter restaurant code : ";
            cin >> restaurantCode;

            cout << "Enter coupon code : ";
            cin >> couponCode;

            cout << "Enter the date from which coupon is valid from : ";
            cin >> validFrom;

            cout << "Enter the date till which coupon is valid : ";
            cin >> validUntil;
            
            cout << "Enter the date on which it has to be used : ";
            cin >> usedDate;
            
            couponsList[counter] = BOGOCoupon(restaurantCode, couponCode, validFrom, validUntil);

            if(hasValidCoupon(restaurantCode, couponCode) && redeemCoupon(couponCode) && couponsList[counter].isValid(usedDate)) {
                cout << endl << "Provided coupon is valid and now accumulated" << endl;
                Restaurant :: couponsRedeemedCount++;
            }
        }
        
        bool hasValidCoupon(string resCode, string coupCode) {
            if(resCode[0] == coupCode[0] && resCode[1] == coupCode[1]) return true;
            
            cout << endl << "Provided coupon is not valid" << endl;
            return false;
        }
        
        bool redeemCoupon(string coupon) {
            for(int i = 0; i < counter; i++) {
                if(redeemCoupons[i] == coupon) {
                    cout << endl << "This coupon is already redeemed" << endl;
                    return false;
                }
            }
            
            redeemCoupons[counter] = coupon;
            return true;
        }
};

int main() {
    
    Restaurant r1("Food Haven", "City Center"), r2("Pixel Bites", "Cyber street");
    
    r1.setMenuAndPriceList("Sushi    ", 250, "Pad Thai", 180, "Mango Tango", 300), r2.setMenuAndPriceList("Binary Burger", 400, "Quantum Quinoa", 200, "Data Donuts", 150);
    
    cout << "Menu of Food Haven" << endl;
    r1.displayMenu();
    
    cout << endl << "Menu of Pixel Bites" << endl;
    r2.displayMenu();
    
    User u1("Umar", 19, 46486), u2("Ali", 30, 74563);
    
    u1.accumulateCoupon(), u2.accumulateCoupon();

    return 0;
}
