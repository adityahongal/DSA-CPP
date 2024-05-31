#include <iostream>
#include <limits.h>
#include <algorithm>
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

// void sortZeroOne( int brr[], int n ){

//     int zeroCount = 0;
//     int oneCount = 0;

//     // Counting
//     for ( int i = 0; i < n; i++ ){
//         if ( brr[i] == 0 ){
//             zeroCount++;
//         }
//         if( brr[i] == 1 ){
//             oneCount++;
//         }
//     }

//     // Insertion
//     int i = 0;
//     for ( ;i < zeroCount; i++){
//         brr[i] = 0;
//     }
//     for ( ;i < n; i++ ){
//         brr[i] = 1;
//     }

//     cout << "The sorted array is: " << endl;
//     for ( int i = 0; i < n; i++ ){
//         cout << brr[i] << " ";
//     }
// }

// Print all pairs

// void printPairs(int arr[], int n) {
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             cout << arr[i] << ", " << arr[j] << endl;
//         }
//     }
// }

// Two Sum in arrays

// bool checkTwoSum(int arr[], int n, int target){

//     // Check all pairs
//     for( int i = 0; i < n; i++){
// for ( int j = 0; j < n; j++){                       // use (int j = i + 1; j < n; j++) to get unique and relevant pairs
//             if ( arr[i] + arr[j] == target ){
//                 // cout << arr[i] << ", " << arr[j] << endl;
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// Prinnt all Triples in arrays

// void printAllTriplets( int arr[], int n){
//     int count = 0;
//     for ( int i = 0; i < n; i++){
//         for ( int j = 0; j < n; j++){
//             for ( int k = 0; k < n; k++){
//                     cout << arr[i] << ", " << arr[j] << ", " << arr[k] << endl;
//                     count++;
//             }
//         }
//     }
//     cout << "The total number of triplets is: " << count << endl;
// }

// Three Sum in arrays

// void checkThreeSum(int arr[], int n, int target)
// {
//     // Check all pairs
//     for (int i = 0; i < n; i++){
//         for (int j = i + 1; j < n; j++){                        // use (int j = i + 1; j < n; j++) to get unique and relevant pairs
//             for (int k = j + 1; k < n; k++){
//                 if (arr[i] + arr[j] + arr[k] == target){
//                     cout << arr[i] << ", " << arr[j] << ", " << arr[k] << endl;
//                 }
//             }
//         }
//     }
// }

// Shifting an array or cyclically rotating an array

void rotateArray(int arr[], int size, int shift){
    int n = shift%size;                     // To find start position of rotation,suppose shift = 2, size = 6,then finalShift = 2 

    if (n == 0){
        // no need to do anything
        return;
    }

    // Step 1: Copy last two digits(finalshift) into an temp array
    int temp[1000];
    int index = 0;
    for (int i = size - n; i < size; i++){
        temp[index] = arr[i];
        index++;
    }

    // Step 2: Shift array elements by n places
    for( int i = size -1; i >= 0; i--){
        if( i - n >= 0 ){
            arr[i] = arr[i - n];                                        // Starts from last plaace and paste's whatever it is by n places
        }
    }

    // Step 3: copy temp elements into original array
    for( int i = 0; i < n; i++){
        arr[i] = temp[i];
    }
}

int main()
{

    // int arr[100];
    // int size;
    // cout << "Enter the size of the array: " << endl;
    // cin >> size;

    // // Get user input for array elements
    // cout << "Enter the elements of the array: " << endl;
    // for (int index = 0; index < size; ++index) {
    //     cin >> arr[index];
    // }

    // findSingleNumber(arr, size);

    // // Sort 0's and 1's
    // int brr[] = { 0,1,1,0,1,1,0};
    // int sortSize = 7;

    // // sortZeroOne(brr, sortSize);                        // Sorting using own method
    // sort (brr, brr+sortSize);                             // Sorting using inbuilt Sort function
    // cout << "The sorted array is: " << endl;
    // for ( int i = 0; i < sortSize; i++ ){
    //     cout << brr[i] << " ";
    // }

    // printPairs(arr, size);

    // Two Sum in arrays
    // int arr[] = {10,20,30,40};
    // int n = 4;
    // bool ans = checkTwoSum(arr,n,690);
    // if ( ans == true ){
    //     cout << "Pair found" << endl;
    // }
    // else{
    //     cout << "Pair not found" << endl;
    // }

    // Check Three Sum in arrays
    // int arr[] = {10, 20, 30, 40};
    // int n = 4;
    // checkThreeSum(arr, n,70);

    // Shifting the array by n positions
    int arr[] = {10,20,30,40,50,60};
    int size = 6;
    int n = 2;                                  // cyclically rotate array by 2 places

    cout << "Before: " << endl;
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    rotateArray(arr, size, n);

    cout << "\nAfter: " << endl;
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}