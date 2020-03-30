// Templates -- called 'generics' in Java 
#include <iostream> 
using namespace std; 

template <class T>                      //List<int> l; 
class List { 
    
    struct node { 
        T val; 
        node *next; 
    };
#include <iostream>

struct node{
	node *next;
	int val;
};
class List {
public:
	node *head;
	node *current;
	void make_node(int data);
	void print_node();
	List();
};

List::List() {
	head = NULL;
	current = NULL;
}

void List::make_node(int data) {
	node *temp;
	temp = new node;
	if (head == NULL)
		
	{
		head = new node;
		head->val = data;
		current = head;
		current->next = temp;
	}
	else
	{
		
		temp->val = data;
		current->next = temp;
		temp->next = NULL;
	}

}
    node *head, *last;

    void delete_after_node(node *current); 

    public: 
    List();
    void push(T val); 
    T pop();
    void print_list();  
};

template <class T>
List<T>::List() { 
    last = head = NULL; 
}


template <class T>
void List<T>::push(T val) { 
    node *temp = new node; 
    temp->val = val;
    temp->next = NULL; 

    if (last == NULL) {         // need this when list is empty
        head = temp; 
        last = temp; 
    } else {                    // for all other cases 
        last->next = temp; 
        last = last->next; 
    } 
}

template <class T>
T List<T>::pop() {
    T val; 

    if (head->next == NULL) {       // only one element in list 
        val = last->val;            // save val for later use 
        delete head;                // delete head 
        head = NULL;                // nothing left in list now 
        last = NULL; 
    } else {                        // all other cases 
        val = last->val;            // save val for later use     
        node *current = head; 
        while(current->next != last) { 
            current = current->next; 
        }
        // now current is just before last. So, delete last 
        delete_after_node(current); 
        last = current; // also need to move last 
    } 

    return val; // now return the value we saved later 
}

template <class T>
void List<T>::delete_after_node(node *current) { 
    node* temp = current->next; 
    current->next = current->next->next; 
    delete temp;
}

template <class T>
void List<T>::print_list() { 
    node *current = head; 
    cout << "[ " ; 
    while (current != NULL) { 
        cout << current->val << " "; 

        current = current->next; 
    }
    cout << "]" << endl; 
}



int main() { 
    List<int> l; 

    cout << "Creating integer list ... " << endl; 
    l.push(5);          // leads to segmentation fault at first 
    l.push(15);
    l.print_list(); 

    l.pop(); 
    l.print_list(); 



    cout << "Creating string list ... " << endl; 
    List<string> l2; 
    // l2.push(5);         // error 
    l2.push("student_1");          
    l2.push("student_2");
    l2.print_list(); 

    l2.pop(); 
    l2.print_list(); 


    return 0; 
}
