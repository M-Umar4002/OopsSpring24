#include <iostream>

using namespace std;

class Logo {
    string design;
    friend class Platform;
    
    public :
        Logo(string design) : design(design) {}
};

class Platform {
    public :
        void updateLogo(Logo &logo, string design) {
            logo.design = design;
        }
        
        void displayLogo(Logo &logo) {
            cout << "Design : " << logo.design << endl;
        }
};

class Server {};

int main() {
    Logo logo("Blue Bird");
    
    Platform p;
    
    cout << "Before updating logo" << endl;
    p.displayLogo(logo);
    
    p.updateLogo(logo, "Doge Coin");
    
    cout << endl << "After updating logo" << endl;
    p.displayLogo(logo);

    return 0;
}
