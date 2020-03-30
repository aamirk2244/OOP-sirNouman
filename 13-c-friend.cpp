#include <iostream> 
using namespace std; 

class Employee { 
    private: 
    int pay_rate; 

    public: 
    friend void access_pay_rate_directly(Employee e); 

    // these are called setters and getters 
    void set_pay_rate(int pay_rate) {   
        if(pay_rate > 14) { 
            this->pay_rate = pay_rate; 
        } else { 
            cout << "Pay rate "<< pay_rate <<" not acceptable. Not setting ... " << endl; 
        }
    }

    int get_pay_rate() { 
        return pay_rate; 
    }
};

void access_pay_rate_directly(Employee e) { 
    cout << "Pay rate: " << e.pay_rate << endl;   // horrible idea ... 
}

int main() { 
    Employee e; 

    e.set_pay_rate(25); 
    cout << "Current pay rate: " << e.get_pay_rate() << endl; 

    access_pay_rate_directly(e);    
}