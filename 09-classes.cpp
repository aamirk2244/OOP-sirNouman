#include <iostream>
#include <string> 
using namespace std; 

class Employee { 
    public: 
    string name; 
    string cnic; 
    int id; 

    void sign_in(); 
    void sign_out(); 
};


void Employee::sign_in() { 
    cout << "Signing in the employee: " + name << endl; 
}

int main() { 
    Employee e1; 
    e1.name = "Ali"; 

    cout << e1.name << endl; 
    e1.sign_in(); 
    // e1.sign_out();    // linker error 



    Employee *e; 
    e = new Employee; 

    e->name = "Usman"; 
    e->sign_in(); 

    return 0; 
}

