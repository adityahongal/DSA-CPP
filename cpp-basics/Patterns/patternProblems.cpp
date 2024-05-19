#include<iostream>
using namespace std;

// void numericHollowHalfPyramid(int n){

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

void numericHollowInvertedHalfPyramid(int n){

    for ( int row = 0; row < n; row++){
        for ( int col = row + 1; col <= n; col++){
            // cout << col;
            if ( col == row + 1 || col == n || row == 0)
            cout << col;
            else
            cout << " ";
        }
        cout << endl;
    }
}

int main(){

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // numericHollowHalfPyramid(n);
    numericHollowInvertedHalfPyramid(n);

    return 0;
}