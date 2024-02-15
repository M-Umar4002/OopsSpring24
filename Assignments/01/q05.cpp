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
        
        void setMenuAndPriceList(string menu1, float price1, string menu2, float price2, string menu3, float price3) {
            
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
    string couponCode, restaurantCode;
    int validFrom, validUntil;
    
    public : 
        BOGOCoupon();
        BOGOCoupon(string cCode, int vFrom, int vUntil, string resCode) {
            couponCode = cCode, validFrom = vFrom, validUntil = vUntil, restaurantCode = resCode;
        }

        bool isValid(int usedDate) {
            if(validFrom <= usedDate && validUntil >= usedDate) {
                cout << "Coupon is within its validity period" << endl;
            } else{
                cout << "Coupon is not in its validity period" << endl;
            }
        }

        friend class User; 
};

class User {
    string name, redeemCoupons[15];
    BOGOCoupon couponsList[15];
    int age, mobileNumber;
    static int counter;
    
    public : 
        User(string n, int a, int mb) {
            name = n, age = a, mobileNumber = mb;
        }

        void accumulateCoupon() {
            string couponCode, restaurantCode;
            int validFrom, validUntil;

            cout << "Enter detais of resturant " << counter+1 << endl << "Enter restaurant code : ";
            cin >> couponsList[counter].restaurantCode;

            cout << "Enter coupon code : ";
            cin >> couponsList[counter].couponCode;

            cout << "Enter the date from which coupon is valid from : ";
            cin >> couponsList[counter].validFrom;

            cout << "Enter the date till which coupon is valid : ";
            cin >> couponsList[counter].validUntil;

            if(hasValidCoupon(couponsList[counter], couponsList[counter].couponCode) && !redeemCoupon(couponsList[counter].couponCode)) counter++;
        }
        
        bool hasValidCoupon(BOGOCoupon& bg, string coupon) {
            if(bg.restaurantCode[0] == coupon[0] && bg.restaurantCode[1] == coupon[1]) return true;
            
            cout << "Coupon code is not valid" << endl;
            return false;
        }
        
        bool redeemCoupon(string coupon) {
            for(int i = 0; i < counter; i++) {
                if(redeemCoupons[i] == coupon) {
                    cout << "This coupon is already redeemed" << endl;
                    return false;
                }
            }

            redeemCoupons[counter] = coupon;
            return true;
        }
};

int main() {
    
    Restaurant r1("Food Haven", "City Center"), r2("Pixel Bites", "Cyber street");



    return 0;
}
