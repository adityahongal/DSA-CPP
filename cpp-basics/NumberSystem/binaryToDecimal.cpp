// Binary to decimal conversion

// 1. Multiply each digit with its place value 
// 2. add up all place values 
// 3. sum is the decimal number
// place value example 

// In decimal place value 
// 123 ->
// 1 = 100 = 1 * 10 pow 2
// 2 = 20 = 2 * 10 pow 1
// 3 = 3 = 3 * 10 pow 0      Note 10 pow 0 is always 1 anything to power 0 is always 1
// Adding all give 100 + 20 + 3 = 123

// In binary place value
// 1010 -> 
// 1 = 1 * 2 pow 3
// 0 = 0 * 2 pow 2
// 1 = 1 * 2 pow 1
// 0 = 0 * 2 pow 0
// adding all values 8 + 0 + 2 + 0 = 10
// digit * (base pow i)


// Note - The base value of the decimal is 10 while base value of binary is 2.


#include<iostream>
#include<cmath>
using namespace std;

int binaryToDecimal(int n) {
    
    int decimal = 0;
    int i = 0;
    while(n){
        int bit = n % 10;
        decimal = decimal + bit * pow( 2, i++);
        n/= 10;
    }
    return decimal;
}

int main(){

    int binaryNumber;
    cout << "Enter a number: ";
    cin >> binaryNumber;
    cout << binaryToDecimal(binaryNumber) << endl;

    return 0;

}