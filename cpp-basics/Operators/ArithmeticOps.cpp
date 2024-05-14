#include<iostream>
using namespace std;

int main() {

    int a = 10;
    int b = 5;

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    cout << a << " % " << b << " = " << a % b << endl;       // Modulus operator. It gives the remainder

    cout << (5.0/2) << endl;   // Typecasting ==> If floating number is divided by integer number, then result will be floating number
    cout << (5/2) << endl; // Typecasting ==> If integer number is divided by integer number, then result will be integer number
    
    return 0;
}