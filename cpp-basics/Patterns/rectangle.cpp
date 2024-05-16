// Rectangle Patterns

#include<iostream>
using namespace std;

// int main(){

//     // total rows = 3
//     // total columns = 5
//     // every row contains -> 5 stars

//     // row -> outer loop 
//     // column -> inner loop 

//     for(int row = 0; row < 3; row++){
//         for(int col = 0; col < 5; col++){
//             cout << "*" << " ";
//         }
//         // print on newline after every row
//         cout << endl;
//     }
//     return 0;
// }

// CUSTOM RECANTANGLES WITH USER INPUTS

int main (){

    int length;
    int width;

    cout << "Enter length: ";
    cin >> length;

    cout << "Enter width: ";
    cin >> width;

    for (int row=0; row < length; row++){
        for (int col = 0; col < width; col++){
            cout << "*" << " ";
        }
        cout << endl;
    }
    return 0;
}