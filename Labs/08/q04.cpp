#include <iostream>
using namespace std;

class Person {
    public :
        string name;
        int age;
        
        Person(string name, int age) : name(name), age(age) {}
        
        void display() {
            cout << "Name : " << name << endl << "Age : " << age << endl;
        }
};

class Student : public Person {
    public :
        int id;
        double grade;
        
        Student(string name, int age, int id, double grade) : Person(name, age), id(id), grade(grade) {}
};

class Teacher : public Person {
    public :
        string subject;
        int roomNumber;
        
        Teacher(string name, int age, string subject, int roomNumber) : Person(name, age), subject(subject), roomNumber(roomNumber) {}
};

class GraduateStudent : public Student, public Teacher {
    public : 
        GraduateStudent(string name, int age, int id, double grade, string subject, int roomNumber) : Student(name, age, id, grade), Teacher(name, age, subject, roomNumber) {}
        
        void display(){
            cout << "Name : " << Student::name << endl << "Age : " << Student::age << endl << "Id : " << id << endl << "Grade : " << grade << endl << "Subject : " << subject << endl << "Room Number : " << roomNumber << endl;
        }
};

int main() {
    GraduateStudent gs("Umar", 19, 23, 3.7, "Maths", 17);
    gs.display();
    
    return 0;
}
