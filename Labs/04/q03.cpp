#include <iostream>
using namespace std;

class WeekDays {
    string days[7];
    int currentDay;
    
    void initializeDays() {
        days[0] = "Sunday", days[1] = "Monday", days[2] = "Tuesday", days[3] = "Wednesday", days[4] = "Thursday", days[5] = "Friday", days[6] = "Saturday";
    }
    
    public : 
        WeekDays() {
            currentDay = 0;
            initializeDays();
        }
        
        WeekDays(int currDay) {
            currentDay = (currDay-1) % 7;
            initializeDays();
        }
        
        string getCurrentDay() {
            return days[currentDay];
        }
        
        string getNextDay() {
            return days[currentDay+1 > 6 ? currentDay-6 : currentDay+1];
        }
        
        string getPreviousDay() {
            return days[currentDay-1 < 0 ? currentDay+6 : currentDay-1];
        }
        
        string getNthdayFromToday(int n) {
            return days[(currentDay+n)%7];
        }
};

void showWeekDaysInfo(WeekDays w) {
    cout << "Current day : " << w.getCurrentDay() << endl << "Next day : " << w.getNextDay() << endl << "Previous day : " << w.getPreviousDay() << endl << "20th day from current day : " << w.getNthdayFromToday(20) << endl;
}

int main() {

    WeekDays w1;
    
    cout << "Using default constructor" << endl;
    showWeekDaysInfo(w1);
    
    w1 = WeekDays(4);
    
    cout << endl << "Using parametrized constructor" << endl;
    showWeekDaysInfo(w1);

    return 0;
}
