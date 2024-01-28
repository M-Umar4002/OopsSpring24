#include <iostream>
using namespace std;

void takeInput(float* studentMarks[], int totalStudents) {
    for(int i  = 0; i < totalStudents; i++) {
        cout << endl << "Enter marks for Student " << i+1 << endl;
        cout << "Math : " ;
        cin >> studentMarks[i][0];
        cout << "English : " ;
        cin >> studentMarks[i][1];
        cout << "Science : " ;
        cin >> studentMarks[i][2];
    }
}

void calculateResult(float* studentMarks[], int totalStudents) {
    float averageMarks;
    char grade;
    for(int i = 0; i < totalStudents; i++) {
        float totalMarks = 0;
        for(int j = 0; j < 3; j++) totalMarks += studentMarks[i][j];
        averageMarks = totalMarks/3;
        averageMarks >= 90 ? grade = 'A' : averageMarks >= 80 ? grade = 'B' : averageMarks >= 70 ? grade = 'C' : averageMarks >= 60 ? grade = 'D' : grade = 'F';
        cout << endl << "For Student " << i+1 << endl << "Total Marks : " << totalMarks << endl << "Average Marks : " << averageMarks << endl << "Grade : " << grade << endl;
    }
}

int main(){
    int totalStudents;
    
    cout << "Enter total no. of students : ";
    cin >> totalStudents;
    
    float** studentMarks = new float*[totalStudents];
    
    for(int i = 0; i < totalStudents; i++) studentMarks[i] = new float[3];
    
    takeInput(studentMarks, totalStudents);
    calculateResult(studentMarks, totalStudents);

    return 0;
}
