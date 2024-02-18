#include <iostream>
#include <array>
using namespace std;

class Office {
    string location = "";
    int seatingCapacity = 0;
    array<string, 3> furniture = {"", "", ""};
    
    public : 
        Office(string loc = "", int cap = 0, array<string, 3> fur = {"", "", ""}) : location(loc), seatingCapacity(cap), furniture(fur) {}
        
};

int main() {

    Office o1, o2("Saddar"), o3("Saddar", 20), o4("Saddar", 20, {"chair", "table", "door"});

    return 0;
}
