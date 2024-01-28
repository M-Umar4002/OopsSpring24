#include <iostream>
using namespace std;

class Student {
    private :
        float mathMarks, englishMarks, scienceMarks, totalMarks, averageMarks;
        char grade;
        
    public : 
    
        void takeInput();
        void calculateResult();
        void displayResult() {
            calculateResult();
            cout << "Total Marks : " << totalMarks << endl << "Average Marks : " << averageMarks << endl << "Grade : " << grade << endl;
        }
};

void Student :: takeInput() {
    cout << "Math : ";
    cin >> mathMarks;
    cout << "English : ";
    cin >> englishMarks;
    cout << "Science : ";
    cin >> scienceMarks;
}

void Student :: calculateResult() {
    totalMarks = mathMarks + englishMarks + scienceMarks;
    averageMarks = totalMarks/3;
            
    averageMarks >= 90 ? grade = 'A' : averageMarks >= 80 ? grade = 'B' : averageMarks >= 70 ? grade = 'C' : averageMarks >= 60 ? grade = 'D' : grade = 'F';
}

int main(){
    
    int totalStudents;
    
    cout << "Enter total no. of students : ";
    cin >> totalStudents;
    
    Student* allStudents = new Student[totalStudents];
    
    for(int i = 0; i < totalStudents; i++) {
        cout << endl << "Enter marks for Student " << i+1 << endl;
        allStudents[i].takeInput();
    }
    
    for(int i = 0; i < totalStudents; i++) {
        cout << endl << "For Student " << i+1 << endl;
        allStudents[i].displayResult();
    }

    return 0;
}
