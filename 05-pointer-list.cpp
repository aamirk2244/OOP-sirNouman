#include <iostream>
using namespace std;

struct node { 
    int val; 
    node *next; 
};

node* create_node(node *current, int new_node_value) { 
    node *n = new node;   // create node 

    // set values 
    n->val = new_node_value; 
    n->next = NULL; 

    // link "current" node to this new node    
    current->next = n; 

    return n; 
}

void output_list(node *h) { 
    node *current = h; 
    cout << "[ " ; 
    while (current != NULL) { 
        cout << current->val << " "; 

        current = current->next; 
    }
    cout << "]" << endl; 
}


int sum_list(node *h) { 
    int sum = 0; 
    node *current = h; 
    cout << "[ " ; 
    while (current != NULL) { 
        // cout << current->val << " "; 
        sum = sum  + current->val; 

        current = current->next; 
    }
    return sum;  
}

void delete_after_node(node *current) { 
    node* temp = current->next; 
    current->next = current->next->next; 
    delete temp;
}

int main() { 
    node *head;
    head = new node;
    head->val = 2; 
    head->next = NULL;   

    node *current = head; 

    current = create_node(current, 27);
    current = create_node(current, 30); 
    current = create_node(current, 50); 
    current = head;

    output_list(head); 
     
    output_list(head); 


    // return 0; 


    current = head->next; 
    cout << "Going to delete: " << current->val << endl; 
    // head->next = current->next; 
    delete_after_node(head); 
    output_list(head); 

    return 0; 

}
