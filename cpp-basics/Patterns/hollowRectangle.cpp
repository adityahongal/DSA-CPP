// Hollow Rectangle

// * * * * * *
// *         *
// *         *
// * * * * * *

// Observatory point

// row 0 and row 3 contains all stars
// similarly col 0 and col 5 contains all stars
// rest all are blank spaces

#include<iostream>
using namespace std;

int main (){

    int length;
    int width;

    cout << "Enter length: ";
    cin >> length;

    cout << "Enter width: ";
    cin >> width;

    // outer loop
    for (int row=0; row < length; row++){
        // inner loop
        for (int col = 0; col < width; col++){
            // first and last row contains all stars
            if (row == 0 || row == length-1){
                cout << "* " ;
            }
            else {
                // middle rows
                if (col == 0 || col == width-1){            // first and last column contains all stars
                    cout << "* ";
                }
                else {
                    cout << "  ";                            // printing blank spaces
                }
            }
            
        }
        cout << endl;                                       // For printing on next line
    }
    
    return 0;
}