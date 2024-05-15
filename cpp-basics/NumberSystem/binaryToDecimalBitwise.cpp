#include<iostream>
#include<cmath>
using namespace std;

int binaryToDecimalBitwise(int n) {
  // Check if the input is a valid binary number (all bits 0 or 1)
  if (n < 0) {
    return -1; // Handle negative input (optional)
  }
  int decimal = 0;
  while (n) {
    decimal = (decimal & 1) + (n & 1) * 2;
    n >>= 1;
  }
  return decimal;
}

int main(){

    int binaryNumber;
    cout << "Enter a Binary number: ";
    cin >> binaryNumber;
    cout << binaryToDecimalBitwise(binaryNumber) << endl;

    return 0;

}


// The above code doesn't take input as a binary number. Pending Resolution.....