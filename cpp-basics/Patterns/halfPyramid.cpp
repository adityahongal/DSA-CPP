// HALF PYRAMID

#include<iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter value of n: ";
    cin >> n;

    for ( int row = 0; row < n; row++){
        for ( int col = 0; col < row+1; col++){                        // alternatively can use col <= row; cz both are same
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}