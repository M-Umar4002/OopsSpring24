/*
* Programmer: Muhammad Umar
* Student Id: 23K-0023
*/

#include <iostream>
#include <string>
using namespace std;

struct Register {
    int courseId;
    string courseName;
};

struct Student : Register {
    int studentId;
    string firstName, lastName, cellNo, email;
};

Student takeInput() {
    Student stu;

    cout << "Course  Id : ";
    cin >> stu.courseId;

    cout << "Course Name : ";
    cin.ignore();
    getline(cin, stu.courseName);

    cout << "Student  Id : ";
    cin >> stu.studentId;

    cout << "First Name : ";
    cin >> stu.firstName;

    cout << "Last Name : ";
    cin >> stu.lastName;

    cout << "Cell No : ";
    cin >> stu.cellNo;

    cout << "Email : ";
    cin >> stu.email;

    return stu;
}

void printData(Student students[]) {
    for(int i = 0; i < 5; i++) cout << endl << "Details fore Student " << i+1 << endl << "Course Id : " << students[i].courseId << endl << "Course Name : " << students[i].courseName << endl << "Student Id : " << students[i].studentId << endl << "Student's First Name : " << students[i].firstName << endl << "Student's Last Name : " << students[i].lastName << endl << "Cell No : " << students[i].cellNo << endl << "Email : " << students[i].email << endl;
}

int main() {
    Student students[5];

    for(int i = 0; i < 5; i++) {
        cout << endl << "Enter details for student " << i+1 << endl;
        students[i] = takeInput(); 
    }
    
    cout << endl;
    
    printData(students);
}
