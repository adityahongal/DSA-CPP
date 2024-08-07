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

// Max number in an array using recursion
void maxNumInArr(int arr[], int size, int index,int &maxNum) { // v impo &maxNum pass by reference
    // base case
    if (index >= size) {
        return;
    }

    // processing
    maxNum = max(maxNum, arr[index]);

    // recursive call
    maxNumInArr(arr, size, index + 1, maxNum);
}

// Min number in an array using recursion
void minNumInArr(int arr[], int size, int index,int &minNum) { // v impo &minNum
    // base case
    if (index >= size) {
        return;
    }

    // processing
    minNum = min(minNum, arr[index]);

    // recursive call
    minNumInArr(arr, size, index + 1, minNum);
}

void printVector(vector< int > v) {
    cout << "Printing Vector" << endl;
    int size = v.size();
    for (int i = 0; i < size; i++) {
        // cout << v[i] << " "; // method 1
        cout << v.at(i) << endl;
    }
    cout << endl;
}

// Print ans store even number of elements
void evenNumsInArray(int arr[], int size, int index, vector< int > &ans) {
    if (index >= size) {
        return;
    }

    if (arr[index] % 2 == 0) {                   // can also be wriiten as if(!(arr[index] & 1))
        ans.push_back(arr[index]);
    }

    evenNumsInArray(arr, size, index + 1, ans);
}

// Print and Store Odd numbers in an array using recursion
void oddNumsInArray(int arr[], int size, int index, vector< int > &ans) {
    if (index >= size) {
        return;
    }

    if (arr[index] & 1) {                     //if(arr[index] % 2 == 1)
        ans.push_back(arr[index]);
    }

    oddNumsInArray(arr, size, index + 1, ans);
}

// Binary Search using recursion
int binarySearchRecursive(int arr[], int size, int start, int end, int target)
{
    // base case
    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;

    // processing
    if (arr[mid] == target)
    {
        return mid;
    }
    // rest will be handled by recursion
    // arr[mid] not equal to target
    // then target maybe big or small
    if (target > arr[mid])
    {
        // Go right
        return binarySearchRecursive(arr, size, mid + 1, end, target);   //Right Recursive call
    }
    else
    {
        // Go left
        return binarySearchRecursive(arr, size, start, mid - 1, target);   //Left recursive call
    }
}

// Print Digits to Number
// e.g. 389 -> 3,8,9

void digitToNumber(int n){
    if(n == 0){
        return;
    }

    // Recursive call first to avoid printing reversed numbers
    int newNumber = n / 10;
    digitToNumber(newNumber);

    // Print the last digit
    // processing
    int digit  = n % 10;
    cout << digit << " ";
}

int main(){
    // Print array using recursion
    // int arr[] = {10,20,30,40,50};
    // int arr[] = {10,11,12,13,14,15,16,17};
    // int sizeOfArr = sizeof(arr) / sizeof(arr[0]);
    // int index = 0;
    // printArrayRecursive(arr, sizeOfArr, index);

    // Search array using recursion
    // int target = 50;
    // cout << searchArray(arr,sizeOfArr,target,index) << endl;

    // Max number in an array using recursion
    // int maxNum = INT_MIN;
    // maxNumInArr(arr, sizeOfArr, index, maxNum);
    // cout << maxNum << endl;

    // // Min number in an array using recursion
    // int minNum = INT_MAX;
    // minNumInArr(arr, sizeOfArr, index, minNum);
    // cout << minNum << endl;

    // Print and Store Even numbers in an array using recursion
    // vector<int> ans;
    // evenNumsInArray(arr, sizeOfArr, index, ans);
    // printVector(ans);

    // Print and Store Odd numbers in an array using recursion
    // vector<int> ans;
    // oddNumsInArray(arr, sizeOfArr, index, ans);
    // printVector(ans);

    // Binary Search using recursion
    // int arr[] = {10,20,30,40,50,60,70};
    // int sizeOfArr = sizeof(arr) / sizeof(arr[0]);
    // int target = 60;

    // int start = 0;
    // int end = sizeOfArr - 1;
    // int ans = binarySearchRecursive(arr, sizeOfArr, start, end, target);
    // cout << "answer index: " << ans << endl;

    // Digit to number
    cout << "Enter digit: " << endl;
    int n;
    cin >> n;
    digitToNumber(n);

    return 0;
}