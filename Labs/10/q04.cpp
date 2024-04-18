#include <iostream>

using namespace std;

class PrintClass;

class Perimeter {
    int length, breadth;

    friend class PrintClass;

    public : 
        Perimeter(int length, int breadth) : length(length), breadth(breadth) {}

        int findPerimeter() {
            return 2 * (length + breadth);
        }
};

class PrintClass {
    public :
        void printPerimeter(Perimeter &p) {
            cout << "Perimeter : " << p.findPerimeter();
        }
};

int main() {
    Perimeter p(7, 8);

    PrintClass print;

    print.printPerimeter(p);

    return 0;
}
