// Inverted Full Pyramid

#include<iostream>
using namespace std;

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

int main(){

    int n;
    cin >> n;
    invertedFullPyramid(n);
    return 0;
}