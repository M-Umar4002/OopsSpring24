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
        
        virtual void displayProperties() const {}
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
            cout << endl << "Properties of the Circle : " << endl << " - Area : " << area() << endl << " - Perimeter : " << perimeter() << endl << " - Diameter : " << diameter() << endl;
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
            cout << endl << "Properties of the Rectangle : " << endl << " - Area : " << area() << endl << " - Perimeter : " << perimeter() << endl << " - Diagonal : " << diagonal() << endl;
        }
};

class Square : public Shape {
    double length;

    public :
        Square() {
            cout << "Enter length of the side of square : ";
            cin >> length;
        }

        double area() const {
            return length * length;
        }

        double perimeter() const {
            return 4 * length;
        }

        double diagonal() const {
            return length * sqrt(2);
        }

        void displayProperties() const {
            cout << endl << "Properties of the Square : " << endl << " - Area : " << area() << endl << " - Perimeter : " << perimeter() << endl << " - Diagonal : " << diagonal() << endl;
        }
};

class Triangle : public Shape {
    double side1, side2, side3;
    
    protected : 
        Triangle(int a) {}

    public :
        Triangle() {
            cout << "Enter length of side 1 of triangle : ";
            cin >> side1;

            cout << "Enter length of side 2 of triangle : ";
            cin >> side2;

            cout << "Enter length of side 3 of triangle : ";
            cin >> side3;
        }

        virtual double area() const {
            double semiPer = perimeter()/2;

            return sqrt(semiPer * (semiPer - side1) * (semiPer - side2) * (semiPer - side3));
        }

        virtual double perimeter() const {
            return side1 + side2 + side3;
        }

        virtual void displayProperties() const {
            cout << endl << "Properties of the Triangle : " << endl << " - Area : " << area() << endl << " - Perimeter : " << perimeter() << endl;
        }
};

class EquilateralTriangle : public Triangle {
    double side;
    
    public :
        EquilateralTriangle() : Triangle(5) {
            cout << "Enter length of the side of equilateral triangle : ";
            cin >> side;
        }
        
        double area() const {
            double semiPer = perimeter()/2;
            
            return sqrt(semiPer * pow((semiPer - side), 3));
        }
        
        double perimeter() const {
            return 3 * side;
        }

        void displayProperties() const {
            cout << endl << "Properties of the Equilateral Triangle : " << endl << " - Area : " << area() << endl << " - Perimeter : " << perimeter() << endl;
        }
};

void menu() {
    cout << endl << "Please select a shape : " << endl << "\t1. Circle" << endl << "\t2. Rectangle" << endl << "\t3. Square" << endl << "\t4. Triangle" << endl << "\t5. Equilateral Triangle" << endl << "Enter your choice : ";
}

int main() {
    cout << "Welcome to the Geometry Competition Calculator!" << endl;
    
    Shape* shape;
    
    string option = "yes";
    
    while(option == "yes") {
        menu();
        int choice;
        cin >> choice;
        
        cout << endl;
        
        switch(choice) {
            case 1 : 
                shape = new Circle();
                break;
            
            case 2 : 
                shape = new Rectangle();
                break;
                
            case 3 : 
                shape = new Square();
                break;
                
            case 4 : 
                shape = new Triangle();
                break;
                
            case 5 : 
                shape = new EquilateralTriangle();
                break;
        }
        
        shape->displayProperties();
        
        delete shape;
        
        cout << endl << "Do you want to calculate properties for another shape? (yes/no) : ";
        cin >> option;
    }
    
    cout << endl << "Thank you for using the Geometry Competition Calculator!";

    return 0;
}
