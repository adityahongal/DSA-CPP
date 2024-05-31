#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

// void printPairsOne(int arr[], int n) {
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < n; j++) {
//             cout << arr[i] << ", " << arr[j] << endl;
//         }
//     }
// }

// void printPairsTwo(int arr[], int n) {
//     for(int i = 0; i < n; i++) {
//         for(int j = i; j < n; j++) {
//             cout << arr[i] << ", " << arr[j] << endl;
//         }
//     }
// }

// void printPairsThree(int arr[], int n) {
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < i; j++) {
//             cout << arr[i] << ", " << arr[j] << endl;
//         }
//     }
// }

// void printPairsFour(int arr[], int n) {
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j <= i; j++) {
//             cout << arr[i] << ", " << arr[j] << endl;
//         }
//     }
// }

// void printPairsFive(int arr[], int n) {
//     for(int i = 0; i < n; i++) {
//         for(int j = n-1; j >= 0; j--) {
//             cout << arr[i] << ", " << arr[j] << endl;
//         }
//     }
// }

// void printPairsSix(int arr[], int n) {
//     for(int i = 0; i < n; i++) {
//         for(int j = n-1; j > i; j--) {
//             cout << arr[i] << ", " << arr[j] << endl;
//         }
//     }
// }

void printPairsSeven(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            cout << arr[i] << ", " << arr[j] << endl;
        }
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

    // printPairsOne(arr, size);
    // printPairsTwo(arr, size);
    // printPairsThree(arr, size);
    // printPairsFour(arr, size);
    // printPairsFive(arr, size);
    // printPairsSix(arr, size);
    printPairsSeven(arr, size);

    return 0;
}