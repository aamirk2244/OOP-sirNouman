#include <iostream>
#include <string>
using namespace std;

class User {
    int id;
    static int next_id;

    public:
    static int next_user_id() {
        next_id++;
        return next_id;
    }

    User() {
        id = User::next_user_id();
    }

    int get_id() { 
        return id; 
    }
};
int User::next_id = 0;      // initialize the static variable here ... 



int fib(int n); 


int main() {

    User u; 
    cout << "User u id: " << u.get_id() << endl; 

    User v; 
    cout << "User v id: " << v.get_id() << endl;


    // return 0; 





    fib(21); 
    cout << "Total count: " << fib(-1) << endl; 


    return 0;
}




int fib(int n) {
    static int count = 0;

    // just for returning the count 
    if (n == -1) { 
        return count; 
    }

    count += 1; // increment call count 

    if (n <= 1) { 
        return n; 
    } else { 
        return fib(n-2) + fib(n-1); 
    }
    
}
