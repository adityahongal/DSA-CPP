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

int main(){
    exampleOfByReference();
    return 0;
}