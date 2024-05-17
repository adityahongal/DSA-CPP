// Hollow Diamond

#include<iostream>
using namespace std;

void hollowPyramid(int n){
    // outer loop
    for (int row = 0; row < n; row++){
        // 1. Print Spaces - Inner Loop 1
        for ( int col = 0; col < n - row - 1; col++)
            cout << " ";
        
        // 2. Print stars - Inner Loop 2
        for ( int col = 0; col < row + 1; col++){
            if (row == 0 || /*row == n - 1 || */  col == 0 || col == row )
            cout << "* ";
            else
            cout << "  ";
        }
            cout << endl;
        
    }
}

void invertedHollowPyramid(int n){
    
    // outer loop
    for (int row = 0; row < n; row++){

        // 1. Print Spaces - Inner loop 1
        for ( int col = 0; col < row ; col++)
            cout << " ";

        // 2. Print stars - Inner loop 2
        for ( int col = 0; col < n - row; col++){
        
            if (/* row == 0 || */ row == n - 1 || col == 0 || col == n - row - 1 )
            cout << "* ";
            else
            cout << "  ";
        }
            cout << endl;
        
    }
}

void hollowDiamond(int n){

    hollowPyramid(n);
    invertedHollowPyramid(n);
}

int main(){

    int n;
    cin >> n;
    hollowDiamond(n);
    return 0;
}