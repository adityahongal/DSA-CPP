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

int pow(int n) {
    // base case
    if (n == 0) {                   // n to power of 0 = 1
        return 1;
    }

    // Recursive Call
    int ans = 2 * pow(n - 1);
    return ans;
}

int NfibonacciSeriesSum(int n) {
    if ( n == 0 || n == 1) {
        return n;
    }

    int ans = NfibonacciSeriesSum(n - 1) + NfibonacciSeriesSum(n - 2);
    return ans;
}

int sumOfN(int n) {
    if (n == 1) {
        return 1;
    }

    int ans = n + sumOfN(n - 1);
    return ans;
}


int main(){
    // cout << factorial(5) << endl;
    // printReverseCount(10);
    // printCount(10);
    // cout << pow(5) << endl;  // 2 to power of 5
    // cout << NfibonacciSeriesSum(9) << endl;
    cout << sumOfN(5) << endl;
    return 0;
}