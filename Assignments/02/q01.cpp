#include <iostream>
#include <vector>
using namespace std;

class SecurityTool {
    protected :
        string securityLevel;
        float cost;
        int noOfDevices;
    
    public :
        SecurityTool(string securityLevel, float cost, int noOfDevices) : noOfDevices(noOfDevices) {
            if(securityLevel != "High" && securityLevel != "Medium" && securityLevel != "Low") cout << "Inappropriate security level" << endl;
            else this->securityLevel = securityLevel;
            
            if(cost <= 0) cout << "Inappropraite cost of security level" << endl;
            else this->cost = cost;
        }
        
        void performScan() {
            cout << "Performing generic security scan" << endl;
        }
};

class FirewallTool : public SecurityTool {
    vector<int> ports;
    vector<string> protocols;
    
    public :
        FirewallTool(string securityLevel, float cost, int noOfDevices) : SecurityTool(securityLevel, cost, noOfDevices) {}
        
        void generateList() {
            int numFromId = 3;
            
            for(int j = numFromId; j < numFromId + 23; j++) ports.push_back(j+1);
            
            protocols = {"HTTPS", "FTP", "UDP", "ICMP", "SSH", "SNMP"};
        }
        
        void performScan() {
            
            if(securityLevel == "Medium") {
                ports.push_back(ports[22]+1), ports.push_back(ports[22]+2);
            } else if(securityLevel == "Low") {
                
                for(int i = 0; i < 5; i++){
                    ports.push_back(ports[22] + i + 1);
                }
                
                protocols.push_back("TCP"), protocols.push_back("DNS");
            }
            
            cout << endl << "Allowing traffic from the following ports" << endl;
            for(int i = 0; i < ports.size(); i++) cout << ports[i] << (i != ports.size() - 1 ? ", " : " ");
            
            cout << endl << endl << "Allowing traffic from the following protocols" << endl;
            for(int i = 0; i < protocols.size(); i++) cout << protocols[i] << (i != protocols.size() - 1 ? ", " : " ");
        }
};

int main() {
    
    string securityLevel;
    float cost;
    int noOfDevices;
    
    cout << "Enter data" << endl << "Security Level (choose from High, Medium , Low) : ";
    cin >> securityLevel;
    
    cout << "Cost (should be greater than 0) : ";
    cin >> cost;
    
    cout << "No. of devices (should be less than or equals to 10): ";
    cin >> noOfDevices;
    
    cout << endl;
    
    FirewallTool obj(securityLevel, cost, noOfDevices);
    obj.generateList(), obj.performScan();

    return 0;
}
