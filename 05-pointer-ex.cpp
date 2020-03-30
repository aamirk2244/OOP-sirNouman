#include <iostream>
using namespace std;

struct node { 
    int val; 
    node *next; 
};

int main() { 
    node *n;
    n = NULL;  

    n = new node;
    n->val = 1; 

    node *current = NULL; 

    current = new node; 
    current->val = 5; 
    current->next = NULL; 

    n->next = current; 
    cout << "First node value :           " << n->val << endl; 
    cout << "Second node value:           " << n->next->val << endl; 
    cout << "Second node (using current): " << current->val << endl; 


    // creat a third node (note that we're re-using current)
    current = new node; 
    current->val = 3; 
    current->next = NULL;

    n->next->next = current; 
    // n->next gives second node and we set the next of that node to current 

    //      next    next             (need two of "next" to get to 3)
    // { 1 }-->{ 5 }-->{ 3 }
    cout << "Third node value:            " << n->next->next->val << endl; 
    cout << "Third node (using current):  " << current->val << endl; 

    return 0; 

}