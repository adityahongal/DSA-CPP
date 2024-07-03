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

    // do not declare pointer empty because it will store illegal random garbage value
    // instead point it to zero e.g. int* ptr = 0; or nullptr

    int b = 100;
    int *bptr = &b;
    cout << "Before: " << bptr << " " << *bptr << endl;

    bptr = bptr + 1; // gives next + 1byte memory address
    cout << "After: " << bptr << " " << *bptr << endl;

    // Pointer Arithmatics
    *bptr = *bptr + 1;
    cout << "After increment: " << *bptr << endl;

    *bptr = *bptr / 2;
    cout << "Division: " << (*bptr) << endl;
    *bptr = *bptr - 7;
    cout << "Substraction: " << (*bptr) << endl;

    // Copying Pointers
    int x = 666;
    int *y = &x;
    int *z = y;
    cout << "x: " << x << endl;
    cout << "Address of y: " << y << endl;
    cout << "Address of z: " << z << " Value of " << "z: " << *z << endl;

    // Some other examples of accessing pointers
    int d = 200;
    int *dptr = &d;

    cout << endl << d << endl;           // value of d
    cout << &d << endl;                  // address of d
    cout << dptr << endl;                // address stored in dptr
    cout << *dptr << endl;               // value stored in d (holds address of d)
    cout << &dptr << endl;               // address of dptr
    cout << (*dptr)++ << endl;           // increment of 200 by 1
    cout << *dptr << endl;               // it will be 201

    cout << ++(*dptr) << endl;           // it will be 202 but it gives direct output

}

// Pointers behaviour with Arrays
void arrayPointers() {
    int arr[5] = {10, 20, 30, 40, 50};

    cout << arr << endl;               // This gives base address of array
    cout << arr[0] << endl;           // This gives element at index 0
    cout << &arr[0] << endl;          // This also gives base address of array    
    cout << &arr << endl;             // This too gives base address of array

    // Creating Pointer for arrays
    int *ptr = arr;
    cout << "Base address of array stored in pointer: " << ptr << endl;
    cout << "Value of address stored : " << *ptr << endl;
    cout << "Address of Pointer: " << &ptr << endl;

}

int main(){
    // pointersInit();
    arrayPointers();
    return 0;
}