// Assigment operators

// For example, a = a + b
// can be written as a += b;

// For example, a = a - b
// can be written as a -= b;

#include<iostream>
using namespace std;

int main() {

    int arr = 5;

    // arr = arr + 10; can be written as 
    arr += 10;
    cout << arr << endl;

    arr -= 5;
    cout << arr << endl;

    arr *= 5;
    cout << arr << endl;

    arr /= 5;
    cout << arr << endl;

    arr %= 5;
    cout << arr << endl;
    
    return 0;
}