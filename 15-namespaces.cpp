// namespaces
#include <iostream>

// namespaces allow us to create sub-scopes within the global scope
// these can have variables, functions or classes within them  


namespace first {
  int var = 5;
}

namespace second {
  double var = 3.1416;
}

int main () {
    using namespace std;  
    using namespace first;
    using namespace second;             // if you add both, you get an error 

    cout << var << std::endl;
    std::cout << second::var << std::endl;

    // cout << var << endl;                   // can have multiple 'using' declarations 
    return 0;
}