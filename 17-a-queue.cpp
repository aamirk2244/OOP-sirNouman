#include <iostream> 
using namespace std; 

#define SIZE 5

void pause(); 

class Queue { 
    private: 
    int q[SIZE]; 
    int in, out; 
    bool is_empty, is_full; 

    // circular increment 
    int inc(int val);

    public: 
    Queue(); 
    void enqueue(int val);  // spell that as ... enq-ue-ue
    int dequeue();          // deq-ue-ue 

    void print_queue(); 
};

Queue::Queue() { 
    for (int i = 0; i < SIZE; i++) { 
        q[i] = 0; 
    }
    in = out = 0; 
    is_empty = true; 
    is_full = false; 
}

int Queue::inc(int val) { 
    if (val + 1 == SIZE)         // loop around 
        val = 0; 
    else 
        val += 1; 
    return val; 
}

void Queue::enqueue(int val) { 
    if (is_full) {
        throw "Queue full. Cannot enqueue ... "; 
        // cout << "Nahi kerta!" ; 
        // return; 
    } 

    // put where in is and increment in 
    q[in] = val; 
    in = inc(in); 

    // check if we are now full 
    if (in == out) 
        is_full = true; 
    
    // definitely not empty any more 
    is_empty = false;       
}

int Queue::dequeue() { 
    if (is_empty) {
        throw "Queue empty. Cannot dequeue ... "; 
    } 

    // get from where out is and inc out 
    int ret = q[out]; 
    out = inc(out); 

    // see if we are now empty 
    if (in == out) 
        is_empty = true; 

    // definitely not full any more 
    is_full = false;       

    return ret; 
}


void Queue::print_queue() { 
    cout << "[\t"; 
    for (int i = 0; i < SIZE; i++)
        cout << q[i] << "\t"; 
    cout << "]" << endl; 

    cout << " \t"; 
    for (int i = 0; i < SIZE; i++) 
        cout << i << "\t"; 
    cout << " " << endl; 

    cout << " "; 
    for (int i = 0; i <= in; i++) 
        cout << "\t"; 
    cout << "^in" << endl;

    cout << " "; 
    for (int i = 0; i <= out; i++) 
        cout << "\t"; 
    cout << "^out" << endl;

    pause(); 
}


int main() { 
    Queue que; 
    
    que.print_queue();  

    que.enqueue(5); 
    que.print_queue();  

    que.enqueue(11); 
    que.print_queue();  

    que.enqueue(22); 
    que.print_queue();    

    que.enqueue(33); 
    que.print_queue();    
    
    que.enqueue(44); 
    que.print_queue();    

    // que.enqueue(55);          // uncomment and then change is_full 
    que.print_queue();    


    // return 0; 


    try { 


        // let's dequeue a few 
        cout << endl << "Now dequeue ... " << endl; 
        cout << "Got val: " << que.dequeue() << endl;   que.print_queue(); 
        cout << "Got val: " << que.dequeue() << endl;   que.print_queue(); 
        cout << "Got val: " << que.dequeue() << endl;   que.print_queue(); 
        cout << "Got val: " << que.dequeue() << endl;   que.print_queue(); 

        cout << "Got val: " << que.dequeue() << endl;    que.print_queue(); 
        cout << "Got val: " << que.dequeue() << endl;    que.print_queue();      // doesn't work 


    } catch (const char *msg) { 
        cout << msg << endl; ; 
    }

    return 0; 
}






void pause() {
    getchar(); 
}
