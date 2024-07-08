#include <climits>
#include <iostream>
#include <limits.h> // for INT_MAX
#include <vector>   // for vector
using namespace std;

// Printing array using recursion
void printArrayRecursive(int arr[], int size, int index){
    // Base case: if index is greater than or equal to size, return
    if(index >= size)
        return;

    // Print the current element
    // In our case we print 0th index
    // Rest will be handled by recursion
    cout << arr[index] << " ";

    // Recursive call with incremented index
    // starting from 1st index to n-1
    printArrayRecursive(arr, size, index + 1);
}

// Searching array using recursion
bool searchArray(int arr[], int size, int target, int index) {
    if (index >= size) {                     // Target not found
        return false;
    }

    if (arr[index] == target) {             // Target found
        return true;
    }

    bool ans = searchArray(arr, size, target, index + 1);  // Recursive call
    return ans;
}

int main(){
    // Print array using recursion
    int arr[] = {10,20,30,40,50};
    int sizeOfArr = sizeof(arr) / sizeof(arr[0]);
    int index = 0;
    // printArrayRecursive(arr, sizeOfArr, index);

    // Search array using recursion
    int target = 50;
    cout << searchArray(arr,sizeOfArr,target,index) << endl;
    return 0;
}