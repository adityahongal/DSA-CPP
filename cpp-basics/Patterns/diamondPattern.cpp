// Diamond Pattern

#include<iostream>
using namespace std;

void fullPyramid(int n){
    // outer loop
    for (int row = 0; row < n; row++){
        // 1. Print Spaces - Inner Loop 1
        for ( int col = 0; col < n - row - 1; col++)
            cout << " ";
        
        // 2. Print stars - Inner Loop 2
        for ( int col = 0; col < row + 1; col++)
            cout << "* ";
            cout << endl;
        
    }
}

void invertedFullPyramid(int n){
    // outer loop
    for (int row = 0; row < n; row++){

        // 1. Print Spaces - Inner loop 1
        for ( int col = 0; col < row ; col++)
            cout << " ";

        // 2. Print stars - Inner loop 2
        for ( int col = 0; col < n - row; col++)
            cout << "* ";
            cout << endl;
        
    }
}

void diamond(int n){
    fullPyramid(n);
    invertedFullPyramid(n);
}
int main(){

    int n;
    cin>>n;
    diamond(n);
    return 0;
}