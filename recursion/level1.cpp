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

int main(){
    cout << factorial(5) << endl;
    return 0;
}