#include <iostream>

using namespace std;

class Shape {
    int length;

    public :
        Shape() {}

        Shape(int length) {
            this->length = length;
        }

        int calculateArea() {
            return length*length;
        }

        int operator+(Shape shape2) {
            return calculateArea() + shape2.calculateArea();
        }
};

int main() {
    Shape shape1(4), shape2(5);

    cout << "After adding the area of both shapes : " << shape1 + shape2;

    return 0;
}
