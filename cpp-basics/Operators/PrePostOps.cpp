#include<iostream>
using namespace std;

int main() {

    // Unary operators ++ and --

    // Preincrement --> example ++a
    // wrorking condition = 1. Increment it then 2. Use/Access it ---> Answer will be 6

    // int a = 5;
    // cout << ++a ;

    // Post increment --> example a++
    // working condition = 1. Use/Access it then 2. Increment it ---> Answer will be 5

    // int a = 5;
    // cout << a++ << endl;  
    // But it will be incremented to 6 after using/accesing it. To verify that
    // cout << a ;

    // Predecrement --> example --a
    // wrorking condition = 1. Decrement it then 2. Use/Access it ---> Answer will be 9

    // int a = 10;
    // cout << --a ;

    // Post Decrement --> example a--
    // working condition = 1. Use/Access it then 2. Decrement it ---> Answer will be 10

    int a = 10;
    cout << a-- << endl;
    // But it will be incremented to 9 after using/accesing it. To verify that
    cout << a ;

    return 0;
}