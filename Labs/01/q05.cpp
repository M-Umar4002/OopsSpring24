#include <iostream>
using namespace std;

struct Event {
    string name, date, venue, organizer;
};

Event eventInput() {
    Event event;
    
    cout << "Name : ";
    cin.ignore();
    getline(cin, event.name);
    
    cout << "Date (dd/mm/yy) : ";
    cin >> event.date;
    
    cout << "Venue : ";
    cin.ignore();
    getline(cin, event.venue);
    
    cout << "Organizer : ";
    getline(cin, event.organizer);
    
    return event;
}

void findSpecificEvent(Event* events, int totalEvents, string specificDate) {
    for(int i = 0; i < totalEvents; i++) if(events[i].date == specificDate) cout << endl <<  "Event Name : " << events[i].name << endl << "Event Date : " << events[i].date << endl << "Event Venue : " << events[i].venue << endl << "Event Organizer : " << events[i].organizer << endl;
}

int main(){
    
    int totalEvents;
    
    cout << "Enter total no. of events : ";
    cin >> totalEvents;
    
    Event* events = new Event[totalEvents];
    
    for(int i = 0; i < totalEvents; i++) {
        cout << endl << "Enter details for event " << i+1 << endl;
        events[i] = eventInput();
    }
    
    string specificDate;
    
    cout << endl << "Enter date to search for the specific event (dd/mm/yy) : ";
    cin >> specificDate;
    
    findSpecificEvent(events, totalEvents, specificDate);

    return 0;
}
