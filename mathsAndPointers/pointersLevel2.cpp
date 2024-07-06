#include <iostream>
#include <vector>
using namespace std;

// Why array is always passed by reference in a function

void solve(int *arr, int size){
    cout << "Size of array inside solve function: " << sizeof(arr) << endl;     
    // Here we expected size = 20 but got size as 8
    // This happens cz we are getting the size of of int* (its storing in address pointer) of arr instead of actual arr[]
    // Thats why we need to pass array by reference in a function
    cout << "Inside address of arr in solve function: " << &arr << endl;       // Can observe address of arr is different
}

void exampleOfByReference(){
    int arr[] = {10,20,30,40,50};
    cout << "Size of array in main function: " << sizeof(arr) << endl;      // Here 5 elements * size of int = 20 bytes
    cout << "Inside address of arr in main function: " << &arr << endl;
    solve(arr,5);
}

// Double/Multi Pointers
void multiPointers(){
    int a = 50;
    int *p = &a;
    int **q = &p;                             // Double pointer
    int ***r = &q;
    
    cout << "Value of q: " << **q << endl;
    cout << "Value of r: " << ***r << endl;
}

// Use Cases of Pointers
// Stack memory stores pointers,Static variables,temp variables etc
// Heap memory stores dynamic variables like vectors,etc
void heapMemory1(){

    // To create integer in stack memory
    int a = 10;                                     // Static variables,temp variables etc stored in stack memory
    cout << "Value of a in stack: " << a << endl;

    // To create integer in heap memory
    int *p = new int;                               // Here new represents return address, we store that in pointer
    *p = 20;
    cout << "Value of a in heap: " << *p << endl;

    // Deallocate memory
    delete p;
}

void heapMemory2(){
    
    // to create 1D array in stack memory
    int arr[5] = {0};
    cout << arr[0] << arr[1] << arr[2] << endl;
    
    // to create array in heap memory (dynamic memory)
    // when we create an array in heap memory
    // its always initialized with zero
    int *brr = new int[5];
    cout << brr[0] << brr[1] << brr[2] << endl;

}

int main(){
    // exampleOfByReference();
    // multiPointers();
    // heapMemory1(); // Heap memory usage example goes here...
    heapMemory2(); 
    return 0;
}