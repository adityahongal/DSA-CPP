// Hollow Pyramid

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
            if (row == 0 || row == n - 1 || col == 0 || col == row )
            cout << "* ";
            else
            cout << "  ";
        }
            cout << endl;
        
    }
}

int main(){

    int n;
    cin >> n;
    hollowPyramid(n);
    return 0;
}