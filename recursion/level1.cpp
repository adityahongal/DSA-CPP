#include <iostream>
using namespace std;

int factorial(int n) {

    // Base case - Mandatory
    if ( n == 0 || n == 1 ) {
        return 1;
    }

    // Recursive call - Mandatory
    int recursionAnswer = factorial(n - 1);        // factorial(n - 1) is recursion
    int finalAnswer = n * recursionAnswer;         // Recursive Relation
    return finalAnswer;

    // Processing - optional
}

// Print Count N --> 1
// when recursive call is at bottom of function
// It is called Tail Recursive call
void printReverseCount(int n) {
    // base case
    if (n == 0 || n == 1) {
        cout << 1 << endl;
        return;
    }

    // processing
    cout << n << " ";

    // recursive call
    printReverseCount(n - 1);        // Tail Recursion
}

// Print Count 1 --> N
// when recursive call is not at bottom of function
// It is called Head Recursive call
void printCount(int n) {
    // base case
    if (n == 0 || n == 1) {
        cout << 1 << endl;
        return;
    }

    // recursive call
    printCount(n - 1);        // Head Recursion

    // processing
    cout << n << " ";
}

int main(){
    // cout << factorial(5) << endl;
    printReverseCount(10);
    printCount(10);
    return 0;
}