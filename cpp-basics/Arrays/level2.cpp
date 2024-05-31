#include<iostream>
#include<limits.h>
using namespace std;

// Finding the single number (Leetcode Question)

// Every element appears twice except for one number. e.g.  arr[] = { 0,4,2,3,0,4,2} ==> single element is 3
// We use XOR to find that single number
int findSingleNumber( int arr[], int n){
    int ans = 0;
    for (int index = 0; index < n; ++index) {
        ans = ans ^ arr[index];
    }
    cout << "The single number is: " << ans << endl;
    return ans;
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

    findSingleNumber(arr, size);

    return 0;
}