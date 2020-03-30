// To enable C++11 extensions in Dev-CPP: 
// Go to Tools -> Compiler Options
// Add to the following to: "... when calling compiler"
//      -std=gnu++0x   
// OR   -std=c++0x    OR    -std=c++11

// For g++ add: -std=c++11

#include <iostream> 
#include <vector> 
  
using namespace std; 

void output_vector_values(vector<int> v); 
void reverse_output_vector_values(vector<int> v); 

int main() { 
    vector<int> marks;          // a vector is essentially python's list 
  
    for (int i = 1; i <= 5; i++) 
        marks.push_back(i*10);          // is append 


    // alternatively 
    // vector<int> marks{10, 20, 30, 40, 50};         


    int val = marks[1];
    cout << "At index 1: " << val << endl; 
   
    output_vector_values(marks); 
    reverse_output_vector_values(marks);


    // return 0;  




    // let's remove a value from a specific position 
    auto it = marks.begin();  
    marks.erase(it + 1); 
    marks.erase(it + 2);

    output_vector_values(marks); 
    
  
    return 0; 
} 



void output_vector_values(vector<int> v) { 

    // Use v.begin() to get a pointer to the start 
    // (but this isn't an int *) ... It's a really weird pointer called "iterator"
    // We don't know how to declare that. So, let's use the 'auto' keyword here 

    cout << "["; 
    for (auto i = v.begin();   i != v.end();     i++) 
        cout << *i << " "; 
    cout << "]" << endl; 


    // // alternatively 
    // cout << "[";
    // for (int x : v)                  // sort of like the for loop in python
    //     cout << x << " "; 
    // cout << "]" << endl; 
  
}

void reverse_output_vector_values(vector<int> v) { 
    // just change the "begin" to "rbegin" and "end" to "rend" 
    cout << "["; 
    for (auto i = v.rbegin();   i != v.rend();     i++) 
        cout << *i << " "; 
    cout << "]" << endl; 
}



// now create a string vector 
// then create a vector of students (output just their names)