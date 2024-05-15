// Explicit Type Casting

// 1. Aka, Manual Type Conversion
// 2. Allows you to explicitly specify the desired datatype during an assignment or operation
// 3. You use the casting operator, which is represented by parentheses containing the target datatype
// ( ) ----> is called casting operator

// TIPS

// int/int = int
// int/float = float
// float/int = int

#include <iostream>
using namespace std;

int main(){

    // 1. float to int conversion
    int num1 = 10;
    float num2 = 5.5;
    float result = num1 + (int)num2;       // Explicit Conversion from int to float      
    cout << result << endl;         

    // double to integer conversion
    double pi = 3.141592653589793;
    int intePi = (int)pi;                  // Explicit Conversion from double to int
    cout << intePi << endl;

    // float to char conversion
    float floatingNumber = 65.47;
    char charValue = (char)floatingNumber;   // Explicit Conversion from float to char. char behaves as integer and search for ASCII value and returns.
    cout << charValue << endl;

    // int to float conversion
    int a = 10;
    int b = 3.0;                             // Here 3.0 will be considered as integer so in order to get the float value we convert either of the value to float while dividing
    float c = a/((float)b);                    // Explicit Conversion from int to float
    cout << c << endl;

    return 0;
}