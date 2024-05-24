#include<iostream>
using namespace std;

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

    int arr[4];
    fill(arr,arr+4,365);
    cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << endl;
    
    return 0;
}