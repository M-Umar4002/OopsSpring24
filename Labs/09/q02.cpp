#include <iostream>
#include <math.h>
using namespace std;

class Shape {
    public :
        virtual double area() const {
            return 0;
        }

        virtual double perimeter() const {
            return 0;
        }
        
        virtual void displayProperties() const {

        }
};

class Circle : public Shape {
    double radius;

    public :
        Circle() {
            cout << "Enter radius of circle : ";
            cin >> radius;
        }

        double area() const {
            return 3.14 * radius * radius;
        }

        double perimeter() const {
            return 2 * 3.14 * radius;
        }

        double diameter() const {
            return 2 * radius;
        }

        void displayProperties() const {
            cout << "Properties of the Circle : " << endl << "Area : " << area() << endl << "Perimeter : " << perimeter() << endl << "Diameter : " << diameter() << endl;
        }
};

class Rectangle : public Shape {
    double length, width;

    public :
        Rectangle() {
            cout << "Enter length of rectangle : ";
            cin >> length;

            cout << "Enter width of rectangle : ";
            cin >> width;
        }

        double area() const {
            return length * width;
        }

        double perimeter() const {
            return 2 * (length + width);
        }

        double diagonal() const {
            return sqrt(pow(length, 2) + pow(width, 2));
        }

        void displayProperties() const {
            cout << "Properties of the Rectangle : " << endl << "Area : " << area() << endl << "Perimeter : " << perimeter() << endl << "Diagonal : " << diagonal() << endl;
        }
};

class Square : public Shape {
    double length;

    public :
        Square() {
            cout << "Enter length of square : ";
            cin >> length;
        }

        double area() const {
            return length * length;
        }

        double perimeter() const {
            return 4 * length;
        }

        double diagonal() const {
            return length/sqrt(2);
        }

        void displayProperties() const {
            cout << "Properties of the Square : " << endl << "Area : " << area() << endl << "Perimeter : " << perimeter() << endl << "Diagonal : " << diagonal() << endl;
        }
};

class Triangle : public Shape {
    protected:
    double side1, side2, side3;

    public :
        Triangle() {
            cout << "Enter side 1 of triangle : ";
            cin >> side1;

            cout << "Enter side 2 of triangle : ";
            cin >> side2;

            cout << "Enter side 3 of triangle : ";
            cin >> side3;
        }

        double area() const {
            double semiPer = perimeter()/2;

            return sqrt(semiPer * (semiPer - side1) * (semiPer - side2) * (semiPer - side3));
        }

        double perimeter() const {
            return side1 + side2 + side3;
        }

        void displayProperties() const {
            cout << "Properties of the Triangle : " << endl << "Area : " << area() << endl << "Perimeter : " << perimeter() << endl;
        }
};

class EquilateralTriangle : public Triangle {
   //double side;

    public :
        EquilateralTriangle() {
            cout << "Enter length of the side of equilateral triangle : ";
            cin >> side1;
            side2 = side3 = side1;
        }
};

int main() {


    return 0;
}
