// Rectangle Patterns

#include<iostream>
using namespace std;

int main(){

    // total rows = 3
    // total columns = 5
    // every row contains -> 5 stars

    // row -> outer loop 
    // column -> inner loop 

    for(int row = 0; row < 3; row++){
        for(int col = 0; col < 5; col++){
            cout << "*" << " ";
        }
        // print on newline after every row
        cout << endl;
    }
    return 0;
}