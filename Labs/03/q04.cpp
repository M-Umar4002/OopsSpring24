#include <iostream>
using namespace std;

class SmartPhone {
    string brand, model;
    int resolution;
    float ram, rom , storage;
    
    public : 
        void setBrand(string br) {
            brand = br;
        }
        
        void setModel(string mod) {
            model = mod;
        }
        
        void setResolution(int res) {
            resolution = res;
        }
        
        void setRam(float r) {
            ram = r;
        }
        
        void setRom(float r) {
            rom = r;
        }
        
        void setStorage(float stor) {
            storage = stor;
        }
        
        void calls() {
            cout << "Making phone calls" << endl;
        }
        
        void sendMsgs() {
            cout << "Sending messages" << endl;
        }
        
        void wifi() {
            cout << "Connecting to Wi-Fi" << endl;
        }
        
        void internet() {
            cout << "Browsing the internet" << endl;
        }
        
        string getBrand() {
            return brand;
        }
        
        string getModel() {
            return model;
        }
        
        int getResolution() {
            return resolution;
        }
        
        float getRam() {
            return ram;
        }
        
        float getRom() {
            return rom;
        }
        
        float getStorage() {
            return storage;
        }
};

void displayData(SmartPhone sm) {
    cout << "Brand : " << sm.getBrand() << endl << "Model : " << sm.getModel() << endl << "Resolution : " << sm.getResolution() << endl << "RAM : " << sm.getRam() << endl << "ROM : " << sm.getRom() << endl << "Storage : " << sm.getStorage() << endl;
    sm.calls(), sm.sendMsgs(), sm.wifi(), sm.internet();
}

int main(){
    
    SmartPhone sm1, sm2;
    
    sm1.setBrand("Nokia"), sm1.setModel("i5"), sm1.setResolution(5631), sm1.setRam(43.4), sm1.setRom(67.98), sm1.setStorage(68.8);
    cout << "Details of smart phone 1" << endl;
    displayData(sm1);
    
    sm2.setBrand("Samsung"), sm2.setModel("s5"), sm2.setResolution(6454), sm2.setRam(43.765), sm2.setRom(76.98), sm2.setStorage(46.64);
    cout << endl << endl << "Details of smart phone 2" << endl;
    displayData(sm2);
    
    return 0;
}
