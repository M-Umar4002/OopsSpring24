#include <iostream>
using namespace std;

class Appointment {
    double time;
    int cost;
    string deal;
    static int totalAppointments, totalEarnings;
    
    public :
        Appointment(double time, int cost, string deal) : time(time), cost(cost), deal(deal) {
            totalAppointments++;
            totalEarnings += cost;
        }
        
        double getTime() const {
            return time;
        }
        
        int getCost() const {
            return cost;
        }
        
        string getDeal() const {
            return deal;
        }
        
        static int getAverageCost() {
            return double(totalEarnings)/totalAppointments;
        }
};

int Appointment :: totalAppointments = 0;
int Appointment :: totalEarnings = 0;

void displayAppoinmentDetails(Appointment &a) {
    cout << "Time : " << a.getTime() << endl << "Cost : " << a.getCost() << endl << "Deal : " << a.getDeal() << endl << endl;
}

int main() {
    
    Appointment a1(1, 300, "Hair Cut"), a2(3, 400, "Set hair style"), a3(6, 250, "Shave"), a4(7, 350, "Facial");
    
    cout << "Details of Appointment 1" << endl;
    displayAppoinmentDetails(a1);
    
    cout << "Details of Appointment 2" << endl;
    displayAppoinmentDetails(a2);
    
    cout << "Details of Appointment 3" << endl;
    displayAppoinmentDetails(a3);
    
    cout << "Details of Appointment 4" << endl;
    displayAppoinmentDetails(a4);
    
    cout << "Average cost of all appointments : " << Appointment::getAverageCost();
    
    return 0;
}
