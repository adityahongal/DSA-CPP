#include <iostream>
#include <vector>
using namespace std;

void pointersInit() {

    int a = 5;
    cout << "Value of Variable: " << a << endl;             // when we want to access contents of a variable
    cout << "Address of Variable: " << &a << endl;          // when we want to access address of a variable

    // pointer create
    // To store address we need a pointer variable
    int *ptr = &a;

    // acccessing pointers
    cout << "Accessing Pointer itself: " << ptr << endl;
    cout << "Accessing Pointer Value: " << *ptr << endl;
    cout << "Accessing Address of Pointer: " << &ptr << endl;
    cout << "Accessiing Size of int pointer: " << sizeof(ptr) << endl;

    // pointer with different datatypes
    char ch = 'k';
    char *chptr = &ch;
    cout << "Accessiing Size of char pointer: " << sizeof(chptr) << endl;

    long num = 10;
    long *lptr = &num;
    cout << "Accessiing Size of char pointer: " << sizeof(lptr) << endl;

    // the answer of size of different datatype pointers are same why ?
    // because ptr variable stores only address
    // so answer for 32 bit system might be 4 and for 64 bit will be 8
}

int main(){
    pointersInit();
    return 0;
}