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

    // cout << arr << endl;               // This gives base address of array
    // cout << arr[0] << endl;           // This gives element at index 0
    // cout << &arr[0] << endl;          // This also gives base address of array    
    // cout << &arr << endl;             // This too gives base address of array

    // Creating Pointer for arrays
    int *ptr = arr;
    // cout << "Base address of array stored in pointer: " << ptr << endl;
    // cout << "Value of address stored : " << *ptr << endl;
    // cout << "Address of Pointer: " << &ptr << endl;

    // arr = arr + 1;                    // not possible in arrays, cz once array is created it cannot be modified

    // Accessing with pointer
    cout << endl << "Accesing" << endl;
    cout << "Base address of arr: " << arr << endl;
    cout << "Base address accessed through &arr: " << &arr << endl;
    cout << "Value of arr[0]: " << arr[0] << endl;
    cout << "Address of value through &arr[0]: " << &arr[0] << endl;
    cout << "Base address of array stored in pointer: " << ptr << endl;
    cout << "Address of Pointer itself: " << &ptr << endl;
    cout << "Value at stored address: " << *ptr << endl;

    cout << "value at base address + 1 = " << *arr + 1 << endl;
    cout << "Gives the value of the second element of the array: " << *(arr + 1) << endl;
    // *(arr + 1) moves the pointer to the next element in the array. In this case, it points to arr[1].
    // *(arr + 1) then dereferences this pointer, giving you the value of the second element of the array. 
    // In this case, *(arr + 1) is 20.

    cout << "Gives the value of the fourth element of the array: " << *(arr + 3) << endl;

    // Pointers behaviour with char arrays
    char ch[50] = "addy";
    char *chptr = ch;                                           // or you can use &ch both gives base address of array

    cout << "Prints entire string: " << ch << endl;
    cout << "Base Address of char array: " << &ch << endl;
    cout << "Prints Entire String: " << chptr << endl;  
    cout << "Base Address of chptr itself: " << &chptr << endl;  
    cout << "Value at stored address: " << *chptr << endl;          // Gives first letter
    cout << "Gives the value of the fourth letter of the string: " << *(chptr + 3) << endl;
    cout << "chptr + 1: " << chptr + 1 << endl;                     // leaving first character it will print rest of the string

    char ch3 = 'a';
    char *ch3ptr = &ch3;
    cout << "Printing 'a' till null char or garbage char is found: " << ch3ptr << endl;      // print a and untill null char is found with garbage values. Also depends on versions and compiler versions

    // Some more examples of pointer in chars
    char ch4[10] = "RacecaR";
    char *cptr = ch4;

    cout << endl;
    cout << "ch: " << ch4 << endl;
    cout << "&ch: " << &ch4 << endl;
    cout << "*(ch + 3): " << *(ch4 + 3)<< endl;
    cout << "cptr: " << cptr << endl;
    cout << "&cptr: " << &cptr << endl;
    cout << "*cptr: " << *cptr << endl;
    cout << "*(cptr + 3): " << *(cptr + 3) << endl;
    cout << "cptr + 2: " << cptr + 2 << endl;
    cout << "cptr + 4: " << cptr + 4 << endl;

    // Special case
    // Since &ch4[0] is a pointer to the first character of the string "RacecaR", 
    // cout will print the entire string "RacecaR".

    // In C++, when you use cout to print a char*, 
    // it is treated as a C-style string and 
    // cout prints the characters starting from the pointer until it encounters a null terminator (\0).
    cout << "&ch[0]: " << &ch[0] << endl;
}

int main(){
    // pointersInit();
    arrayPointers();
    return 0;
}