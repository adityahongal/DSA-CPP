// Decimal to Binary Conversion

// A. Division method
// 1. Divide the number by 2
// 2. Store remainder ( That will be a bit in binary number 0 or 1)
// 3. Repeat above steps with the quotient until quotient is less than 2 
// 4. Reverse the bits obtained.

// For example
// int n = 10;

// Division | Remainder
// 10/2 = 5 | 0
// 5/2 =  2 | 1
// 2/2 =  1 | 0
// 1/2 =  0 | 1

// 0101 is the remainder, now we have to reverse the bits obtained to get binary representation of 10 which is 1010
// formula for that is
// Remainder -> Remainder * 10 to the power of (no. of remainders) + previous remainder = answer

// for example
// Our remainder is 0101
// 0 -> 0 * 10 to the pow of 0 + 0 = 0
// 1 -> 1 * 10 to the pow of 1 + 0 = 10
// 0 -> 0 * 10 to the pow of 2 + 10 = 10
// 1 -> 1 * 10 to the pow of 3 + 10 = 1010

// Now its representable in integer form as we wanted. Means we want to show output in decimal form itself.



#include<iostream>
#include<cmath>
using namespace std;

int decimalToBinaryDivisionMethod(int n) {
    // Division Method
    int binaryNumber = 0;
    int i = 0;
    while(n>0) {
        int bit = n % 2;
        // cout << bit << endl;
        binaryNumber = bit * pow(10, i++) + binaryNumber;               // To reverse it into integer representation
        n = n / 2;
    }
    return binaryNumber;
}



int main(){

    int n;
    cout << "Enter a number: ";
    cin >> n;
    int binary = decimalToBinaryDivisionMethod(n);
    cout << binary << endl;

    return 0;

}