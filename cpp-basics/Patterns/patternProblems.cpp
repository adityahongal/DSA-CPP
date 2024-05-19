#include<iostream>
using namespace std;

// void numericHollowHalfPyramid(){
//     int n;
//     cout << "Enter the value of n: ";
//     cin >> n;
//     for ( int row = 0; row < n; row++ ){
//         for ( int col = 0; col <= row; col++){
//             if ( col == 0 || col == row || row == n - 1 )
//                 cout << col + 1;
//             else
//                 cout << " ";
//         }
//         cout << endl;
//     }
// }

// void numericHollowInvertedHalfPyramid(){
//     int n;
//     cout << "Enter the value of n: ";
//     cin >> n;
//     for ( int row = 0; row < n; row++){
//         for ( int col = row + 1; col <= n; col++){
//             // cout << col;
//             if ( col == row + 1 || col == n || row == 0)
//             cout << col;
//             else
//             cout << " ";
//         }
//         cout << endl;
//     }
// }

void numericPalindromeEquilateralPyramid(){
    int size;
    cout << "Enter Size of pattern" << endl;
    cin >> size;
    
    for (int i = 0; i < size; i++) {
        // Print leading spaces
        for (int j = 0; j < size - i - 1; j++) {
            cout << " ";
        }
        
        // Print ascending numbers
        for (int j = 0; j <= i; j++) {
            cout << j + 1;
        }

        // Print descending numbers
        for (int j = i - 1; j >= 0; j--) {
            cout << j + 1;
        }

        // Move to the next line
        cout << endl;
    }
}

int main(){

    // numericHollowHalfPyramid();
    // numericHollowInvertedHalfPyramid();
    numericPalindromeEquilateralPyramid();

    return 0;
}