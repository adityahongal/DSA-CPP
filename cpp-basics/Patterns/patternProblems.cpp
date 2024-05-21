#include<iostream>
#include "assert.h"
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

// void numericPalindromeEquilateralPyramid(){
//     int size;
//     cout << "Enter Size of pattern" << endl;
//     cin >> size;
    
//     for (int i = 0; i < size; i++) {
//         // Print leading spaces
//         for (int j = 0; j < size - i - 1; j++) {
//             cout << " ";
//         }
        
//         // Print ascending numbers
//         for (int j = 0; j <= i; j++) {
//             cout << j + 1;
//         }

//         // Print descending numbers
//         for (int j = i - 1; j >= 0; j--) {
//             cout << j + 1;
//         }

//         // Move to the next line
//         cout << endl;
//     }
// }

// void solidHalfDiamond(){
//     int n;
//     cout << "Enter Size of pattern:" << endl;
//     cin >> n;

//     // To print stars in ascending order
//     for ( int row = 0; row < n; row++){
//         for ( int col = 0; col < row + 1; col++){
//             cout << "* ";
//         }
//         cout << endl;
//     }

//     // Then Print stars in descending order
//     for ( int row = 0; row < n - 1; row++ ){
//         for ( int col = 0; col < n - row - 1; col++){
//             cout << "* ";
//         }
//         cout << endl;
//     }
// }

// void fancyPatternOne(){
//     int n;
//     cout << "Enter the size of pattern:" << endl;
//     cin >> n;

//     // It works till only N = 9 so,
//     // if ( n > 9){
//     //     cout << "Please put value <= 9. " << endl;
//     //     return;
//     // }
//     assert(n<=9);           // Can be used instead of above if statement.

//     // outer loop
//     for ( int row = 0; row < n; row++){

//         int start_num_index = 8 - row;             // from where to start index
//         int num = row + 1;                         // start of printing numbers
//         int count_num = num;                      // number of times the number should be printed
//         for ( int col = 0; col < 17; col ++){
//             if ( col == start_num_index && count_num > 0){
//                 cout << num;
//                 start_num_index+=2;                 // the numbers print skipping two indexes
//                 count_num--;
//             }
//             else {
//                 cout << "*";
//             }
//         }
//         cout << endl;
//     }
// }

// void fancyPatternTwo(){
//     int n;
//     cout << "Enter the size of pattern:" << endl;
//     cin >> n;

//     // upper half of pattern
//     int c = 1;
//     for ( int row = 0; row < n; row++){
//         for ( int col = 0; col <= row; col++ ){
//             cout << c ;
//             c++;
//             if ( col < row ){
//                 cout << "*";
//             }
//         }
//         cout << endl;
//     }
//     //cout << "Now C:" << c ;                  // to check the value of start number after upper loop

//     // lower half of pattern
//     int start = c - n;
//     for ( int row = 0; row < n; row++){
//         int k = start;
//         for ( int col = 0; col <= n - row - 1; col ++){                   // col <= n - row - 1
//             cout << k ;
//             k++;
//             if ( col < n - row - 1 ){
//                 cout << "*";
//             }
//         }
//         start = start - ( n - row - 1);
//         cout << endl;
//     }

// }

void fancyPatternThree(){
    int n;
    cout << "Enter the size of pattern:" << endl;
    cin >> n;

    for (int row = 0; row < n; row++) {
        int cond = row <= n/2 ? 2 * row : 2 * ( n - row - 1 );
        for ( int col = 0; col <= cond; col++){
            if ( col <= cond/2 ){
                cout << col + 1;
            }
            else {
                cout << cond - col + 1;
            }
        }
        cout << endl;
    }
    
}

int main(){

    // numericHollowHalfPyramid();
    // numericHollowInvertedHalfPyramid();
    // numericPalindromeEquilateralPyramid();
    // solidHalfDiamond();
    // fancyPatternOne();
    // fancyPatternTwo();
    fancyPatternThree();

    return 0;
}