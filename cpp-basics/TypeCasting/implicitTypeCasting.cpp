// Implicit type casting

// aka Automatic Type Conversion
// Compiler automatically converts one data type to another
// This happens when performing operations involving multiple datatypes and 
// the compiler promotes one type to a larger type to maintain precision


// 1. int to float conversion

// Here the compiler converts int to float because we have been expecting the result to be in float and information will not be lost
// But if we keep int result, the answer will be 15 and 0.5 information will be lost, because integer doesn't hold float values in memory

// 2. char to int conversion

// Here the compiler converts char to int because we have been expecting the result to be in int.
// the ASCII value of 'A' will be used to convert to int for example 65 + 1 = 67 will be the result.

// 3. int to char conversion

// Here the compiler converts int to char because we have been expecting the result to be in char
// the compiler automatically searches for ASCII number 97 and converts the integer 97 to a which is char type

#include <iostream>
using namespace std;

int main(){

    // 1. int to float conversion
    int num1 = 10;
    float num2 = 5.5;
    float result = num1 + num2;       // Implicit Conversion from int to float      
    cout << result << endl;         

    // 2. char to int conversion
    char ch = 'A';
    int a = ch + 1;                  // Implicit conversion from char to int
    cout << a << endl;

    // 3. int to char conversion
    int b = 97;
    char c = b;                      // Implicit conversion from int to char
    cout << c << endl;

    return 0;
}