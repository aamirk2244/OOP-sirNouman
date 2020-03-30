#include <iostream>
using namespace std;

int function_test(int x); // function prototype

void variables_test() {
    int x; // local scope variable

    x = 2147483647;
    cout << "Value: " << x << endl;

    // x = 2147483648;     // can't do that!
    // cout << "int: " << x << endl;

    long y;
    y = 2147483648;
    cout << "long: " << y << endl;

    y = 9223372036854775807;
    cout << "long upper limit: " << y << endl;

    float f;
    f = 3.40282e+38; // 3.40282 x 10^38
    cout << "float: " << f << endl;

    f = 3.40282e+39;
    cout << "float: " << f << endl; // great result

    double g;
    g = 3.40282e+39;
    cout << "double: " << g << endl;
}

void char_test() {
    char x = 'A'; // 65 -- ASCII values  ... Unicode
    cout << "Value of variable = " << x << endl;

    cout << "Converted to int = " << (int)x << endl;
    cout << "Adding 1 = " << (char)(x + 1) << endl;

    // Unicode -- modern ASCII
}

void cin_test() {
    int val;
    cout << "Please enter value: ";
    cin >> val;
    cout << "Received value: " << val << endl;
}

int main() {
    cout << "Hello World" << endl;

    cout << function_test(5) << endl;

    // cin_test();

    // variables_test();

    // char_test();
    return 0;
}

int function_test(int x) {
    cout << "Function received value: " << x << endl;
    return 2 * x;
}