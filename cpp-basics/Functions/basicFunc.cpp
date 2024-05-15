// Function syntax

// return_type function_name( input parameters ){ 
//      definition
// }

// return_type function_name( input parameters );       ------>>  This is only function declaration.

// return_type consists of two datatypes :- Void and non-void
// Void is blank function and return statement is not used. But if used, we cannot return it with a value.
// Non-void can be int,float,char,double

// Order of the function matters. The function declared should be above the main function or it doesnt work.
// If you really want to write and run the code below main function then you have to declare the function above the main code first and then write its definition below main function



#include<iostream>
using namespace std;

// void printCounting(){

//     for ( int i = 1; i <= 5; i++ ){
//         cout << i << " ";
//     }
// }

// int sum ( int a,int b){
//     int totalSum = a + b;
//     return totalSum;
// }

// void printName(){
//     cout << "ADDY" << endl;
// }

void printName();           // Function declaration example

int main(){

    // printCounting();

    // int ans = sum (6,10);
    // cout << ans << endl;

    // function call
    printName();

    return 0;
}

void printName(){
    cout << "ADDY" << endl;   // Function declaration and its definition after main function example
}