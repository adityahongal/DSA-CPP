#include<iostream>
using namespace std;

// Functions with Arrays
void printArray( int arr[], int size){
    for ( int index = 0; index < size; ++index ){
        cout << arr[index] << " ";
    }
}


int main (){

    // // Creating an Array
    // int arr[10];

    // // int brr[];         // Throws an error because size of array is not defined

    // // Initializing an empty array
    // int crr[] = {10,20,80,70,50};

    // int drr[4] = {55};

    // cout << crr[3] << endl;
    // cout << drr[0] << endl;
    // cout << drr[1] << endl;

    // Filling an array

    // int arr[4];
    // fill(arr,arr+4,365);
    // cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << endl;

    // Taking input in a Array

    // int arr[5];
    // for (int i = 0; i < 5; i++){
    //     cout << "Enter the value for the value " << i << endl;
    //     cin >> arr[i];
    // }

    // // Printing the array
    // for(int i = 0; i < 5; i++){
    //     cout << arr[i] << " ";                       // arr[i] is also equal to i[arr]
    // }

    // arr[i] is also equal to i[arr]
    // value at(base address + (datatypeSize * Index)) 
    // above formula give address(memory location) of the index 

    // Functions with Array

    int arr[5] = {10,20,30,40,50};
    int size = 5;

    printArray(arr, size);

    
    return 0;
}