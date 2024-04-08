#include <iostream>
using namespace std;

inline int battingAverage(int runsScored, int dismissals) {
    return runsScored/dismissals;
}

inline float strikeRate(int runsScored, int ballsFaced) {
    return (float(runsScored)/float(ballsFaced))*100;
}

int main() {
    
    int runsScored, ballsFaced, dismissals;
    
    cout << "Enter total number of runs scored by player : ";
    cin >> runsScored;
    
    cout << "Enter total number of balls faced by player : ";
    cin >> ballsFaced;
    
    cout << "Enter total number of times the player has been dismissed : ";
    cin >> dismissals;
    
    cout << endl << "Batting Average : " << battingAverage(runsScored, dismissals) << endl << "Strike Rate : " << strikeRate(runsScored, ballsFaced);
    
    return 0;
}
