#include <iostream>
using namespace std;

class BoardMarker {
    string brand, shade;
    bool refillable, status;

    public :
        void setData(string b, string s, bool ref, bool stat) {
            brand = b, shade = s, refillable = ref, status = stat;
        }

        void getData() {
            cout << "Brand : " << brand << endl << "Shade : " << shade << endl << "Refillable : " << (refillable ? "Yes" : "No") << endl << "Status : " << (status ? "depleted" : "Not depleted") << endl;
        }

        void writing() {
            cout << (status ? "Ink is depleted" : "Ink is not depleted") << endl; 
        }

        void refill() {
            cout << (refillable ? "Can be refilled" : "Cant be refilled") << endl; 
        }
};

int main() {

    BoardMarker m1;

    m1.setData("dollar", "blue", false, true);
    m1.getData();
    m1.writing();
    m1.refill();

    return 0;
}
