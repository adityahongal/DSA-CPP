// B. Bitwise Method
// 1. Obtain bit with bitwise AND operation i.e, (N & 1)
// 2. Right Shift N by 1 (N = N >> 1)
// 3. Repeat above steps till N > 0.
// 4. Reverse the bits obtained.

#include<iostream>
#include<cmath>
using namespace std;

int decimalToBinaryBitwiseMethod(int n) {
    // Bitwise Method
    int binaryNumber = 0;
    int i = 0;
    while(n>0) {
        int bit = (n & 1);
        // cout << bit << endl;
        binaryNumber = bit * pow(10, i++) + binaryNumber;               // To reverse it into integer representation
        n = n >> 1;                                                     // Right shift N by 1
    }
    return binaryNumber;
}

int main(){

    int n;
    cout << "Enter a number: ";
    cin >> n;
    int binary = decimalToBinaryBitwiseMethod(n);
    cout << binary << endl;

    return 0;

}