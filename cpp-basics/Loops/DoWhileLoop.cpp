// Do While Loop Syntax

// initialization
// do
// {
//    logic
//    updation
// } while(condition);

#include<iostream>
using namespace std;

int main() {

    // for ( int i = 1; i <= 5; i++) {
    //     cout << i << " " ;    
    // } 

    // The above for loop when converted to do while loop below

    int i = 1;
    do {

        // Logic
        cout << i << " " ;
        
        // updation
        i++;

    } while (i <= 5);  

    return 0;
}