#include <iostream>

using namespace std;

class Employee {
    int id;
    string name;
    
    public : 
        Employee(int id, string name) : id(id), name(name) {}
    
        virtual double calculatePay() const {
            return 0.0;
        }
        
        virtual void displayDetails() const {
            cout << "ID : " << id << endl << "Name : " << name << endl;
        }
};

class FullTimeEmployee : public Employee {
    double monthlySalary;
    
    public : 
        FullTimeEmployee(int id, string name, double monthlySalary) : Employee(id, name), monthlySalary(monthlySalary) {}
        
        double calculatePay() const {
            return monthlySalary;
        }
        
        void displayDetails() const {
            Employee::displayDetails();
            cout << "Type : Full-Time" << endl << "Monthly Salary : " << monthlySalary << endl;
        }
};

class PartTimeEmployee : public Employee {
    int hourlyWage, hoursWorked;
    
    public : 
        PartTimeEmployee(int id, string name, int hourlyWage, int hoursWorked) : Employee(id, name), hourlyWage(hourlyWage), hoursWorked(hoursWorked) {}
        
        double calculatePay() const {
            return hourlyWage * hoursWorked;
        }
        
        void displayDetails() const {
            Employee::displayDetails();
            cout << "Type : Part-Time" << endl << "Hourly Wage : " << hourlyWage << endl << "Hours Worked : " << hoursWorked << endl;
        }
};

int main() {
    FullTimeEmployee fte(101, "AAA", 5000);
    
    PartTimeEmployee pte(102, "BBB", 15, 40);
    
    cout << "Dispalying Details : " << endl << endl;
    fte.displayDetails();
    
    cout << endl;
    pte.displayDetails();
    
    cout << endl << "Calculating Pay : " << endl << "Full-Time Employee Pay : $" << fte.calculatePay() << endl << "Part-Time Employee Pay : $" << pte.calculatePay() << endl << endl;
    
    Employee* emp = &fte;
    cout << "Using base class pointer to calculate Full-Time Employee Pay : $" << emp->calculatePay();
}
