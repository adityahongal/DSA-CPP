#include<iostream>
#include<limits.h>
using namespace std;

// Finding the single number (Leetcode Question)

// Every element appears twice except for one number. e.g.  arr[] = { 0,4,2,3,0,4,2} ==> single element is 3
// We use XOR to find that single number

// int findSingleNumber( int arr[], int n){
//     int ans = 0;
//     for (int index = 0; index < n; ++index) {
//         ans = ans ^ arr[index];
//     }
//     cout << "The single number is: " << ans << endl;
//     return ans;
// }

// Sort 0's and 1's

void sortZeroOne( int brr[], int n ){

    int zeroCount = 0;
    int oneCount = 0;

    // Counting
    for ( int i = 0; i < n; i++ ){
        if ( brr[i] == 0 ){
            zeroCount++;
        }
        if( brr[i] == 1 ){
            oneCount++;
        }
    }

    // Insertion
    int i = 0;
    for ( ;i < zeroCount; i++){
        brr[i] = 0;
    }
    for ( ;i < n; i++ ){
        brr[i] = 1;
    }

    cout << "The sorted array is: " << endl;
    for ( int i = 0; i < n; i++ ){
        cout << brr[i] << " ";
    }
}


int main(){

    int arr[100];
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;

    // Get user input for array elements
    cout << "Enter the elements of the array: " << endl;
    for (int index = 0; index < size; ++index) {
        cin >> arr[index];
    }

    // findSingleNumber(arr, size);

    // Sort 0's and 1's
    int brr[] = { 0,1,1,0,1,1,0};
    int sortSize = 7;

    sortZeroOne(brr, sortSize);

    return 0;
}