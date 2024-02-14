#include <iostream>
using namespace std;

class Table {
    int totalSeats, occupiedSeats, freeSeats;
    bool clean;
    friend void occupyTable(Table tables[], int totalFriends);

    public : 
        Table() {
            totalSeats = 4, clean = true, occupiedSeats = 0, freeSeats = 4;
        }

        Table(int cap) {
            if(cap != 4 && cap != 8) {
                if(abs(cap-4) > abs(cap-8)) {
                    totalSeats = 8;
                } else {
                    totalSeats = 4;
                }
            } else {
                totalSeats = cap;
            }
            clean = true, occupiedSeats = 0;
        }

        void useTable(int totalFriends) {
            if(clean) {
                if(totalFriends <= 4) {
                    freeSeats = 4-totalFriends;
                    occupiedSeats = totalFriends;
                } else {
                    freeSeats = 8-totalFriends;
                    occupiedSeats = totalFriends;
                }
                cout << "Table is being used by " << totalFriends << " friends" << endl;
            } else {
                cout << "Table is not clean so it cant be used" << endl;
            }
        }

        void haveLunch() {
            cout << "Having lunch" << endl;
            clean = false;
        }
        
        void leaveTable() {
            cout << "Leaving the table" << endl;
            occupiedSeats = 0, freeSeats = totalSeats;
        }

        void cleanTable() {
            if(!clean && !occupiedSeats) {
                cout << "Table is cleaned" << endl;
                clean = true;
            }
        }
};

void occupyTable(Table tables[], int totalFriends) {
    for(int i = 0; i < 5; i++) {
        if(tables[i].totalSeats >= totalFriends){
            cout << "Assigned table : " << i+1 << endl;
            tables[i].useTable(totalFriends);
            cout << "Seating capacity of the table : " << tables[i].totalSeats << endl;
            break;
        }
    }
}

void emptyTable(Table tables[], int tableNo) {
    tables[tableNo].leaveTable(), tables[tableNo].cleanTable();
}

int main(){

    Table tables[5];
    tables[0] = tables[2] = tables[3] = Table(4);
    tables[1] = tables[4] = Table(8);

    cout << "For first group of friends" << endl;
    occupyTable(tables, 4);
    
    cout << endl << endl << "For Second group of friends" << endl;
    occupyTable(tables, 6);

    cout << endl << endl << "Calling functions for table 1" << endl;
    tables[0].useTable(4), tables[0].haveLunch(), tables[0].leaveTable(), tables[0].cleanTable();

    cout << endl << endl << "Calling emptyTable function for table 2" << endl;
    emptyTable(tables, 1);

    return 0;
}
