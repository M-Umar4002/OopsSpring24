#include <iostream>

using namespace std;

class Base {
    int a;

    public :
        Base() {}

        Base(int a) {
            this->a = a;
        }

        Base operator--(int) {
            this->a *= 4;
            return a;
        }

        Base operator--() {
            this->a /= 4;
            return a;
        }

        void display() {
            cout << "The value is : " << a << endl;
        }
};

int main() {
    Base b(24);

    b.display();

    --b;
    b.display();

    b--;
    b.display();

    return 0;
}
