#include <iostream> 
using namespace std; 

void print_move(int, char, char);    // short form of the signature. Don't need variable names.



void move_disk(int n, char from_rod, char to_rod, char aux_rod) { 
    if (n == 1) { 
        // just the smallest disk. Can be moved directly anywhere 
        print_move(1, from_rod, to_rod);  
        return; 
    } 

    // move all-minus-largest from FROM to AUX (using TO as extra)
    move_disk(n-1, from_rod, aux_rod, to_rod); 
                      
    
    // move largest disk 
    print_move(n, from_rod, to_rod);        
    
    // move all-minus-largest from AUX (where we left them) to TO (using FROM as extra)
    move_disk(n-1, aux_rod, to_rod, from_rod); 
} 
  


int main() { 
    int n = 2; // Number of disks 
    move_disk(n, 'A', 'C', 'B');  // A, B and C are names of rods 
    return 0; 
} 


void print_move(int disk, char from_rod, char to_rod) { 
    cout << "Move disk " << disk << " from rod " << from_rod << " to rod " << to_rod << endl; 
}
