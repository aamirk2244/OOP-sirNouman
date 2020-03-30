#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std; 

// can ignore this for now ------
// #if defined(_WIN32)
//     #define SEP "\\" 
// #else 
//     #define SEP "/" 
// #endif 
// ------------------------------



void output_matrix(int a[][3], int rows, int cols){ 
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) { 
            cout << a[i][j] << " ";
        } 
        cout << endl; 
    } 
}  

void bin_example() { 
    int pixels[3][3]; 
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            pixels[i][j] = 1 + i*j; 

    output_matrix(pixels, 3, 3); 

    // writing to a file 
    ofstream fout("data.txt", ios::binary);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            fout.write((char *)&pixels[i][j],   sizeof(int) );

    fout.close();    // notice what happens when we miss this

    // read data back in 
    cout << "Resetting pixels ... " << endl; 
    for (int i = 0; i < 3; i++) 
        for (int j = 0; j < 3; j++) 
            pixels[i][j] = 0;

    output_matrix(pixels, 3, 3); 

    cout << "Reading again ... " << endl; 
    ifstream fin("data.txt", ios::binary);  // try missing file 

    // also try !fin in the condition 
    if(fin.fail()) {    
        cout << "Failed to read file ... " << endl; 
    } else { 
        for (int i = 0; i < 3; i++) 
            for (int j = 0; j < 3; j++)
                fin.read((char *)&pixels[i][j], sizeof(int)); 
    }
    fin.close(); 

    output_matrix(pixels, 3, 3); 
}

/*
void char_example() { 
    // output file stream instance 
    ofstream fout; 
    string filename = "sample.txt";  // also try relative path 

    string line = "My test line ... "; 
  
    fout.open(filename);      // default is ios::out, try ios::app 
    fout << line << endl;     // as simple as that! 
 
    fout.close();             // need to remember this! 
  
    // input file stream instnace 
    ifstream fin; 

    fin.open(filename); 
    while (fin) { 
        getline(fin, line); 
        cout << line << endl; 
    } 
    fin.close(); 
} */

int main() 
{   
    cout << "int: " << sizeof(int) << endl; 
    cout << "char: " << sizeof(char) << endl; 

    // char_example(); 
    bin_example(); 
    
    return 0; 
} 
