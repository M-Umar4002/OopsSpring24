#include <iostream>

using namespace std;

class Convert {
    protected :
        float val1, val2;
    
    public :
        Convert(float val1) : val1(val1) {}
    
        virtual void compute() {}
};

class L_T0_G : public Convert {
    public :
        L_T0_G(float val1) : Convert(val1) {}
    
        void compute() {
            val2 = val1 * 0.264172;
            cout << val1 << " L : " << val2 << " gal" << endl;
        }
};

class F_T0_C : public Convert {
    public :
        F_T0_C(float val1) : Convert(val1) {}
    
        void compute() {
            val2 = (val1 - 32) / 1.8;
            cout << val1 << " °F : " << val2 << " °C" << endl;
        }
};

int main() {
    Convert* l_to_g = new L_T0_G(4);
    l_to_g->compute();
    
    Convert* f_to_c = new F_T0_C(70);
    f_to_c->compute();

    return 0;
}
