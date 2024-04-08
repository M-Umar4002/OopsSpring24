#include <iostream>
#include <vector>
using namespace std;

class Course {
    string code, name;
    int creditHours;
    
    public :
        Course(string code, string name, int creditHours) : code(code), name(name), creditHours(creditHours) {}
    
        string getCode() const {
            return code;
        }
        
        string getName() const {
            return name;
        }
        
        int getCreditHours() const {
            return creditHours;
        }
};

class Student {
    string id, name;
    vector<Course> courses;
    
    public :
        Student(string id, string name) : id(id), name(name) {}
        
        void enroll(Course &c) {
            courses.push_back(c);
        }
        
        void drop(Course &c) {
            for(int i = 0; i < courses.size(); i++) {
                if(courses[i].getCode() == c.getCode()) courses.erase(courses.begin()+i);
            }
        }
        
        int getTotalCreditHours() {
            int total = 0;
            
            for(Course &c : courses) total += c.getCreditHours();
            
            return total;
        }
        
        void printEnrolledCourses() {
            for(int i = 0; i < courses.size(); i++) {
                if(!i) cout << "Details of all courses student is currently enrolled in : " << endl;
                
                cout << endl << "Course " << i+1 << endl << "Code : " << courses[i].getCode() << endl << "Name : " << courses[i].getName() << endl << "Credit Hours : " << courses[i].getCreditHours() << endl;
            }
        }
};

int main() {
    
    Course c1("C1", "PF", 1), c2("C2", "OOP", 2), c3("C3", "DSA", 3);
    
    Student s("S3-10", "Umar");
    
    s.enroll(c1), s.enroll(c2), s.enroll(c3), s.printEnrolledCourses();
    
    cout << endl << "Total credit Hours : " << s.getTotalCreditHours() << endl;
    
    s.drop(c1);
    
    cout << endl << "After dropping one course" << endl << endl;
    s.printEnrolledCourses();
    
    return 0;
}
