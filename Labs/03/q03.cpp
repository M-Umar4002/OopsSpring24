#include <iostream>
using namespace std;

class Calendar {
    string jan[30], feb[30], mar[30], apr[30], may[30], june[30], july[30], aug[30], sep[30], oct[30], nov[30], dec[30];
    int year;
    
    void showTasksFor(string month[]) {
        for(int i = 0; i < 30; i++) if(month[i] != "") cout << "Day " << i+1 << " : " << month[i] << endl;
        cout << endl;
    }
    
    public : 
        Calendar(int y) : year(y) {}
    
        void addTask(int date, int month, string task) {
            switch(month) {
                case 1 : 
                    jan[date-1] = task;
                    break;
                case 2 : 
                    feb[date-1] = task;
                    break;
                case 3 : 
                    mar[date-1] = task;
                    break;
                case 4 : 
                    apr[date-1] = task;
                    break;
                case 5 : 
                    may[date-1] = task;
                    break;
                case 6 : 
                    june[date-1] = task;
                    break;
                case 7 : 
                    july[date-1] = task;
                    break;
                case 8 : 
                    aug[date-1] = task;
                    break;
                case 9 : 
                    sep[date-1] = task;
                    break;
                case 10 : 
                    oct[date-1] = task;
                    break;
                case 11 : 
                    nov[date-1] = task;
                    break;
                case 12 : 
                    dec[date-1] = task;
                    break;
            }
        }
        
        void removeTask(int date, int month) {
            switch(month) {
                case 1 : 
                    jan[date-1] = "";
                    break;
                case 2 : 
                    feb[date-1] = "";
                    break;
                case 3 : 
                    mar[date-1] = "";
                    break;
                case 4 : 
                    apr[date-1] = "";
                    break;
                case 5 : 
                    may[date-1] = "";
                    break;
                case 6 : 
                    june[date-1] = "";
                    break;
                case 7 : 
                    july[date-1] = "";
                    break;
                case 8 : 
                    aug[date-1] = "";
                    break;
                case 9 : 
                    sep[date-1] = "";
                    break;
                case 10 : 
                    oct[date-1] = "";
                    break;
                case 11 : 
                    nov[date-1] = "";
                    break;
                case 12 : 
                    dec[date-1] = "";
                    break;
            }
        }
        
        void displayTasks() {
            cout << endl << "Details for all Months" << endl << endl << "For January : " << endl << "-------------" << endl;
            showTasksFor(jan);
            cout << "For February : " << endl << "--------------" << endl;
            showTasksFor(feb);
            cout << "For March : " << endl << "-----------" << endl;
            showTasksFor(mar);
            cout << "For April : " << endl << "-----------" << endl;
            showTasksFor(apr);
            cout << "For May : " << endl << "---------" << endl;
            showTasksFor(may);
            cout << "For June : " << endl << "----------" << endl;
            showTasksFor(june);
            cout << "For July : " << endl << "----------" << endl;
            showTasksFor(july);
            cout << "For August : " << endl << "------------" << endl;
            showTasksFor(aug);
            cout << "For September : " << endl << "---------------" << endl;
            showTasksFor(sep);
            cout << "For October : " << endl << "-------------" << endl;
            showTasksFor(oct);
            cout << "For November : " << endl << "--------------" << endl;
            showTasksFor(nov);
            cout << "For December : " << endl << "--------------" << endl;
            showTasksFor(dec);
        }
};

int main(){
    Calendar calendar(2024);
    
    calendar.addTask(10, 3, "Play Cricket");
    calendar.addTask(13, 3, "Study OOP");
    calendar.addTask(20, 5, "Celebrate friend's birthday");
    calendar.addTask(4, 8, "Go to Islamabad");
    calendar.addTask(23, 3, "Enjoy your holidays");
    calendar.addTask(18, 11, "Go out to watch a movie");
    calendar.removeTask(13, 3);
    calendar.displayTasks();

    return 0;
}
