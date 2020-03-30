#include <iostream> 
using namespace std; 

void if_test() { 
    int age = 16; 

    if (age >= 18) { 
        cout << "You can vote!" << endl; 
    } else { 
        cout << "You are too young!" << endl; 
    }
}


float get_grade_points(char grade) { 
    float val; 

    switch(grade) { 
        case 'A': 
            val = 4.0; 
        case 'B': 
            val = 3.0; 
        case 'C': 
            val = 2.0; 
        case 'D': 
            val = 1.0; 
        default: 
            val = 0.0; 
    }

    return val; 
}

void loops_test() { 
    int i = 0; 

    cout << "Starting while loop ... " << endl; 
    while (i < 5) { 
        cout << i << endl; 
        i++; 
    }

    cout << endl << "Starting for loop ... " << endl; 
    for (int i = 0; i < 3; i++) { 
        cout << i << endl;    
    }
    cout << "After for, value of i is: " << i << endl; 

    cout << endl << "Starting do-while loop ... " << endl; 
    i = 0;   // what if we make this start from 10? 
    do { 
        cout << i << endl; 
        i++; 
    } while(i < 5); 
}

int main() { 
   // if_test(); 

    // cout << get_grade_points('A') << endl; 

     loops_test(); 
    return 0; 
} 
