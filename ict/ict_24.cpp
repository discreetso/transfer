// two major limitations of arrays: fixed data type and fixed size

#include <iostream>
#include <stdio.h>
using namespace std;

// function prototype
void array_test();
void two_dim(); 
void struct_examp();

// main function
int main() {
    // array_test();
    // two_dim();
    struct_examp();

    return 0;
}

// function definition (1 dimension array)
void array_test() {
    int a[5];           // fixed size, contiguous memory location

    cout << "Before assignment: " << endl;
    for(int i = 0; i < 5; i+=1) {
        cout << a[i] << ' ';
    }
    cout << endl;

    cout << "cleaning the garbage values ..." << endl;
    cout << "After cleaning and initializing the array .." << endl;

    for (int i = 0; i < 5; i+=1){
        a[i] = 0;
        cout << a[i] << ' ';
    }
    cout << endl;

    cout << "After assigning the values ..." << endl;
    for(int i = 0; i < 5; i+=1){
        a[i] = i * i;
        cout << a[i] << ' ';
    }
    cout << endl;
}

// function definition (2-D array)
void two_dim() {
    int a[2][3];

    // output the garbage values
    cout << "outputing the garbage values: " << endl; 
    for(int i = 0; i < 2; i+=1){
        for(int j = 0; j < 3; j+=1) {
            cout << a[i][j] << ' ';  
        }
        cout << endl;
    }

    // assigning the values
    cout << "assigning the values..." << endl;
    int val = 1; 
    for(int i = 0; i < 2; i+=1){
        for(int j = 0; j < 3; j+=1) {
            a[i][j] = val;
            val += 1;   
        }
    }

    // outputting the values
    cout << "outputting the assigned values: " << endl;
    for(int i = 0; i < 2; i+=1){
        for(int j = 0; j < 3; j+=1) {
            cout << a[i][j] << ' ';  
        }
        cout << endl;
    }
}

// tackling the problem of fixed datatype of arrays, we use structures in c/c++
void struct_examp() {
    struct student{             // student is a user-defined data-type
    int rollno;
    float marks;
    };

    student s1;
    s1.marks = 59.5;
    s1.rollno = 23;
    cout << "Student 1 has " << s1.marks << " marks";
}

