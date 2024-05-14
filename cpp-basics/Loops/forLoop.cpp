// Syntax for For Loop

// for (initialization; condition; update){
    // code to be executed in each iteration
// }


#include<iostream>
using namespace std;

int main(){

    // for loop
    // for( int count = 1; count <= 10; count =count + 1){

    //     cout << "Addy --> " << count << endl;
    // }

    // counting numbers from 51 to 69

    // for( int i=51; i < 70; i++){

    //     cout << i << endl;
    // }


    // Importance of break keyword

    // In the numbers of 1 to 10, print till the end of 5. Here break keyword is used exit loop.

    // for( int i = 1; i < 10; i++){

    //     cout << i << " ";

    //     if( i == 5){
    //         break;
    //     }
    // }


    // Importance of Continue keyword

    // It skips the iteration

    for (int i = 1; i <= 5; i++){

        if( i == 4){
            continue;
        }
        cout << i << " ";

    }


    return 0;
}