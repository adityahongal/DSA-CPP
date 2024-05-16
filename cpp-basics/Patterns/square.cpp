// Square Patterns

#include<iostream>
using namespace std;

int main(){

    // total rows = 4
    // every row contains -> 4 stars

    // row -> outer loop 
    // column -> inner loop 

    for(int row = 0; row < 4; row++){
        for(int col = 0; col < 4; col++){
            cout << "*" << " ";
        }
        // print on newline after every row
        cout << endl;
    }
    return 0;
}