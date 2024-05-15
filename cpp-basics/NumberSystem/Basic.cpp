// Number System
// Is a method to represent numeric values or quantities using different digits  
// examples

// 1.
// Decimal Number system 
// uses 0-9 and its Base is 10 (base is the number of symbols or digits a Number system uses)

// 2.
// Binary Number system
// uses base 2
// it uses 1 and 0

// Decimal to Binary Conversion

// A. Division method
// 1. Divide the number by 2
// 2. Store remainder ( That will be a bit in binary number 0 or 1)
// 3. Repeat above steps with the quotient until quotient is less than 2 
// 4. Reverse the bits obtained.

// B. Bitwise Method
// 1. Obtain bit with bitwise AND operation i.e, (N & 1)
// 2. Right Shift N by 1 (N = N >> 1)
// 3. Repeat above steps till N > 0.
// 4. Reverse the bits obtained.