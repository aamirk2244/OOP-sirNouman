#include <iostream>
#include <string> 
using namespace std; 

class Plugin { 
    public: 
    // virtual void apply_filter(int img[5][5]) {      // need to add 'virtual' here 
    //     // what does a "filter" do? We can't say ... 
    //     cout << "Function apply_filter for Plugin called ... Not doing anything ... " << endl; 
    // }

    virtual void apply_filter(int img[5][5]) = 0; 
    // that's a pure virtual function! 
    // if we have a pure virtual function in a class, it becomes an `abstract class' 
    // any child is also abstract unless it defines this function ... 
}; 


class MakeItWhite : public Plugin { 
    public: 

    // overriding ... 
    void apply_filter(int img[5][5]) {
        for (int i = 0; i < 5; i++) { 
            for (int j = 0; j < 5; j++) { 
                img[i][j] = 255; 
            }
        }
    }
};


class MakeItBlack : public Plugin { 
    public: 

    // overriding ... 
    void apply_filter(int img[5][5]) {
        for (int i = 0; i < 5; i++) { 
            for (int j = 0; j < 5; j++) { 
                img[i][j] = 0; 
            }
        }
    }
};


/// CLASSES END HERE ... everything else is global 


void init_matrix(int a[5][5]); 
void output_matrix(int a[5][5]); 
Plugin * select_plugin(); 


int main() { 
    int pic[5][5]; 
    
    init_matrix(pic); 

    cout << "Before: " << endl; 
    output_matrix(pic); 

    Plugin p; 
    p.apply_filter(pic); 

    MakeItBlack mib; 
    mib.apply_filter(pic); 

    cout << "After MakeItBlack: " << endl; 
    output_matrix(pic); 

    // MakeItWhite miw;  
    // miw.apply_filter(pic); 

    // cout << "After MakeItWhite: " << endl; 
    // output_matrix(pic); 

    // init_matrix(pic); // reset to original 

    
    // return 0; 

    // Let's do it another way ... 
    Plugin *p;                   // notice that we don't have the name of any specific plugin here ... 
    
    p = select_plugin();         // reference variable of a parent class can hold the address of a child class! 
    p->apply_filter(pic); 
    cout << "After Plugin Application: " << endl; 
    output_matrix(pic); 


    // return 0; 
    

    // Plugin q;                // this gives an error if the class is abstract 

}


Plugin * select_plugin() { 
    string plugin_name = "MIB"; 

    Plugin *p; 
    if (plugin_name == "MIW")
        p = new MakeItWhite;
    else 
        p = new MakeItBlack; 
        
    return p; 
}


// helper functions 
void init_matrix(int a[5][5]) { 
    int val = 0; 
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) { 
            a[i][j] = val;
            val += 1; 
        } 
    }
}

void output_matrix(int a[5][5]){ 
    for (int i = 0; i < 5; i++) { 
        for (int j = 0; j < 5; j++) { 
            cout << a[i][j] << " ";
        } 
        cout << endl; 
    } 
}  
