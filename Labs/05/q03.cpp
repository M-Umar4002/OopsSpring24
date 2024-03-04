#include <iostream>
using namespace std;

class ValidateString {
    string str;
    
    public : 
        ValidateString(string word) : str(word) {}
        
        // If we not make this finction constant there will be a probability that we could accidentally change the actual string, but we only wants to validate string and not to do any changes in this function, thats why we have made this function constant
        bool checkString() const {
            for(int i = 0; i < str.length(); i++) if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) return false;
            return true;
        }
};

int main() {
    ValidateString s1("gjAAwfsfZgdj"), s2("6527][}"), s3("gvGGFMdgv hsd"), s4("12!@%jh*&");

    cout << (s1.checkString() ? "Valid string" : "Invalid string") << endl << (s2.checkString() ? "Valid string" : "Invalid string") << endl << (s3.checkString() ? "Valid string" : "Invalid string") << endl << (s4.checkString() ? "Valid string" : "Invalid string") << endl;

    return 0;
}
