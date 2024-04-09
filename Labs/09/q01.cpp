#include <iostream>

using namespace std;

const double pi = 3.14; // global constant variable for pi

class Shape {
    public :
        // Area function for circle
        double area(double radius) {
            return pi * radius * radius;
        }
        
        // Area function for rectangle
        double area(double length, double width) {
            return length * width;
        }
        
        // Area function for triangle
        float area(float base, float height) {
            return (base * height)/2;
        }
        
        // Perimeter function for circle
        double perimeter(double radius) {
            return 2 * pi * radius;
        }
        
        // Perimeter function for rectangle
        double perimeter(double length, double width) {
            return 2 * (length + width);
        }
        
        // Perimeter function for triangle
        double perimeter(double side1, double side2, double side3) {
            return side1 + side2 + side3;
        }
};

int main() {
    Shape shape;
    
    // Calling area and perimeter functions for circle
    cout << "Area of Circle : " << shape.area(6.5) << endl << "Perimeter of Circle : " << shape.perimeter(6.5) << endl;
    
    // Calling area and perimeter functions for circle
    cout << endl << "Area of Rectangle : " << shape.area(8, 11.3) << endl << "Perimeter of Rectangle : " << shape.perimeter(8, 11.3) << endl;
    
    // Calling area and perimeter functions for circle
    cout << endl << "Area of Triangle : " << shape.area(10.f, 7.6f) << endl << "Perimeter of Triangle : " << shape.perimeter(8.2, 9.4, 10.6) << endl;
}
