#include <iostream>
using namespace std;

void pointer_test()
{
    int x = 25;
    cout << "Value of x itself                 : " << x << endl;
    cout << "Value of address of x             : " << &x << endl;
    // return ;

    int *p; // an integer pointer

    p = &x; // address-of operator

    cout << "Value of p itself                 : " << p << endl;
    cout << "Value at address (pointed to by p): " << *p << endl;

    // This -- *p -- is called pointer dereferencing
    // Let's see this in the tutor! Yay!
}

void pointer_test_array()
{
    int nums[10];

    for (int i = 0; i < 10; i++)
        nums[i] = i;

    int *p;
    p = nums; // notice the missing &

    cout << "Value of nums     : " << nums << endl;
    cout << "Value of &nums[0] : " << &nums[0] << endl;
    cout << "Value of p        : " << p << endl;
    cout << "Value of *p       : " << *p << endl;

    // return;

    cout << "Inc p" << endl;
    p++;
    cout << "Value of p : " << p << endl;
    cout << "Value of *p: " << *p << endl;

    // return;

    cout << "Entering loop after resetting p --- " << endl;

    p = &nums[0]; // or nums
    for (int i = 0; i < 10; i++)
    {
        cout << "Value of p : " << p << "   ";
        cout << "Value of *p: " << *p << "   ";

        cout << "Inc p" << endl;
        p++;
    }
}

void null_pointer_test()
{
    int x = 25;

    int *p, *q;
    p = &x;
    q = NULL; // points to nothing
    

    cout << "Value of p  = " << p << endl;
    cout << "Value of *p = " << *p << endl;
    cout << "Value of q  = " << q << endl;
    cout << "Value of *q = " << *q << endl; // check for NULL before using
}

int main()
{
    // pointer_test();

//     pointer_test_array();

    null_pointer_test();

    return 0;
}
