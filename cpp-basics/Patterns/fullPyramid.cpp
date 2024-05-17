// Full Pyramid

// We run inner loop twice

// If there is only a single statement in for loop, then there is no need of flower braces

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

int main(){

    int n;
    cin >> n;
    fullPyramid(n);
    return 0;
}