#include<iostream>
#include<limits.h>
using namespace std;

// Functions with Arrays
void printArray( int arr[], int size){
    for ( int index = 0; index < size; ++index ){
        cout << arr[index] << " ";
    }
}

// Linear Search Algorithm
bool findtarget( int arr[], int size, int target ){
    cout << "Enter the target value: ";
    cin >> target;

    // Traverse the array
    for ( int index = 0; index < size; ++index ){
        if ( arr[index] == target ){
            return true;
        }
    }
    return false;
}

// Finding Maximum Number in Array
int findMax( int arr[], int size ){
    int maxAns = INT_MIN;                                         // requires #include limits.h INT_MAX, INT_MIN
    for ( int index = 0; index < size; ++index ){
        maxAns = max(maxAns, arr[index]);                         // Inbuilt function
    }
    return maxAns;
}

// count 0's and 1's in an array 
void printZeroesAndOnes(int arr[],int size){
    int zeroCount = 0;
    int oneCount = 0;
    for ( int index = 0; index < size; ++index ){
        int currentElement = arr[index];
        if ( currentElement == 0 ){
            zeroCount++;
        }
        else if ( currentElement == 1 ){
            oneCount++;
        }
    }
    cout << "Number of 0's: " << zeroCount << endl;
    cout << "Number of 1's: " << oneCount << endl;
}

// Extreme Printing
// void extremePrint(int arr[],int n){

//     int left = 0;
//     int right = n-1;

//     while ( left <= right ){

//         if( left == right ){
//             // print only 1 time
//             cout << arr[left] << " ";
//             left++;
//         }
//         else{
//         cout << arr[left] << " ";
//         cout << arr[right] << " ";
//         left++;
//         right--;
//         }
//     }
// }

// TRY SWAPPING AND REVERSE

// Swapping in arrays

// void swap(int arr[], int size) {
 
//  int i, j;
//     cout << "Enter the indices of the elements to swap: " << endl;
//     cin >> i >> j;

//     if (i < 0 || i >= size || j < 0 || j >= size) {
//         cout << "Invalid indices. Please enter indices between 0 and " << size - 1 << "." << endl;
//         return;
//     }

//     int temp = arr[i];
//     arr[i] = arr[j];
//     arr[j] = temp;

//     cout << "Array after swapping elements at indices " << i << " and " << j << ": " << endl;
//     for (int index = 0; index < size; ++index) {
//         cout << arr[index] << " ";
//     }
//     cout << endl;
// }

// Reversing in arrays

void reverseArray(int arr[], int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }

    cout << "Array after reversing: " << endl;
    for (int index = 0; index < size; ++index) {
        cout << arr[index] << " ";
    }
    cout << endl;
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

    int arr[100];
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;

    // Get user input for array elements
    cout << "Enter the elements of the array: " << endl;
    for (int index = 0; index < size; ++index) {
        cin >> arr[index];
    }

    // printArray(arr, size);

    // bool ans = findtarget(arr,size,53);            // Linear Search function
    // cout << "ans: " << ans << endl;

    // cout << "max number is: " << findMax( arr, size) << endl;

    // printZeroesAndOnes(arr,size);

    // extremePrint(arr,size);

    // swap(arr,size);

    reverseArray(arr,size);

    return 0;
}