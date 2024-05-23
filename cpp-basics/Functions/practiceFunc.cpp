#include<iostream>
#include <vector>
using namespace std;

// Kilometer to Miles
// void KMtoMiles(){
//     float km;
//     cout << "Enter Kilometer: ";
//     cin >> km;
//     float _1km = 0.621371;
//     float miles = km * _1km;
//     cout << km << " Kilometer = " << miles << " Miles" << endl;
// }

// void printAllDigits(){
//     int n;
//     cout << "Enter a number: ";
//     cin >> n;
//     while(n>0){
//         int onesPlaceDigit = n % 10;
//         cout << "Digit is : " << onesPlaceDigit << endl;
//         n = n / 10;
//     }
// }

// void AreaOfCircle(){
//     float radius;
//     cout << "Enter radius: ";
//     cin >> radius;
//     float area = 3.14 * radius * radius;
//     cout << "Area of circle is: " << area << endl;
// }

// void checkEvenOdd(){
//     int n;
//     cout << "Enter a number: ";
//     cin >> n;
//     // if(n % 2 == 0){
//     //     cout << n << " is even" << endl;
//     // }else{
//     //     cout << n << " is odd" << endl;
//     // }

//     // Bitwise method
//     if((n & 1) == 0 ){
//         cout << n << " is even" << endl;
//     }
//     else{
//         cout << n << " is odd" << endl;
//     }
// }

// void Factorial(){
//     int n;
//     cout << "Enter a number: ";
//     cin >> n;
//     long long int fact = 1;
//     for ( int i = 1; i <= n; i++){
//         fact = fact * i;
//         cout << fact << endl;
//     }
// }

// check prime or not
// bool CheckPrime() {
//   // divisible by one or self only.
//   // not perfectly divisible by other numbers

//   // method to solve
//   // we will not check divisibility with self and 1
//   // we will check with all the other numbers that in the range of
//   // 2 to N-1,
//   // where N is the number you are checking prime for,
//   // 2 is to skip 1 and N-1 is to skip the number you are checking

//   int num;
//   cout << "Enter a number: ";
//   cin >> num;

//   bool isPrime = true;  // Flag to track if the number is prime

//   for (int i = 2; i < num; i++) {
//     if (num % i == 0) {
//       isPrime = false;
//       break;  // Exit the loop if not prime
//     }
//   }

//   if (isPrime) {
//     cout << num << " is a prime number" << endl;
//   } else {
//     cout << num << " is not a prime number" << endl;
//   }

//   return isPrime; // You can optionally return the primality result
// }

// print all prime numbers from 1 to N

// bool CheckPrime(int num, bool printFlag) {
//   for (int i = 2; i < num; i++) {
//     if (num % i == 0) {
//       if (printFlag) {
//         cout << num << " is not a prime number" << endl;
//       }
//       return false;
//     }
//   }

//   if (printFlag) {
//     cout << num << " is a prime number" << endl;
//   }
//   return true;
// }

// void PrintPrimeFromOneToN(int N) {
//     cout << "Prime Number from 1 to " << N << " are :" << endl;

//   for (int i = 1; i <= N; i++) {
//     bool isPrime = CheckPrime(i, false);
//     if (isPrime) {
//       cout << i << " ";
//     }
//   }
//   cout << endl;
// }

// reverse an integer
// LEETCODE PROBLEM

// int ReverseInteger(int x) {
//   int ans = 0 ;
//   bool isNeg = false; 

//   if ( x <= INT_MIN){
//     return 0;
//   }

//   if (x < 0) {
//     isNeg = true;
//     x = -x;
//   }

//   while (x > 0) {
    
//     if ( ans > INT_MAX/10 ){
//       return 0;
//     }

//     int digit = x % 10;
//     ans = ans * 10 + digit;
//     x = x / 10;
//   }
//   cout << (isNeg ? -ans : ans) << endl;
// }

// set k- th bit
// a value k is given which represent index value of binary representation of an
// integer the index starts from right to left ex 3210 <-- the program is
// written to achieve -> replace k the position in binary representation of an
// integer to 1 k can be converted into bitwise representation by left shift the
// value of k with 1 ex 1 << k by doing a bitwise OR we will be able to achieve
// this efficiently

// void SetKthBit(int decimalNumber, int k) {
//   int mask = 1 << k;
//   int result = decimalNumber | mask;
//   cout << "Result after set bit of " << decimalNumber << " with " << k
//        << " bits is: " << result << endl;
// }

// convert temperature
// void ConvertTemperature(double celcius) {
//   double kelvin = celcius + 273.15;
//   double fahrenheit = celcius * 1.80 + 32.00;

//   vector<double> v;
//   v.push_back(kelvin);
//   v.push_back(fahrenheit);
  
//   cout << celcius << " T0 Fahrenheit :" << v.back() << endl << celcius << " To kelvin :" << v.front() << endl;
// }

// Count all set bits
// set bits is number of 1's present in binary representation

// void countSetBits(){
//   int n;
//   cout << "Enter a number: ";
//   cin >> n;

//   int count = 0;
//   // while (n > 0) {
//   //   int bit = n % 2;
//   //   if (bit == 1) {
//   //     count++;
//   //   }
//   //   n = n / 2;
//   // }

//   // Using Bitwise AND cz it is faster
//   while (n > 0) {
//     int bit = n & 1;
//     if (bit == 1) {
//       count++;
//     }
//     n = n >> 1;              // right shift
//   }
//   cout << count << endl;
// }

// create number using digits
void CreateNumberUsingDigits() {
  int numberOfDigits = 0;
  int digit;
  int num = 0;
  cout << "Enter the number of digits you want to enter" << endl;
  cin >> numberOfDigits;
  for (int i = 0; i < numberOfDigits; ++i) {
    cout << "Enter digit: " << endl;
    cin >> digit;
    num = num * 10 + digit;
    cout << "The Number formed so far " << num << endl;
  }

  cout << endl << "The Final Number formed is " << num << endl;
}

int main(){

    // KMtoMiles();
    // printAllDigits();
    // AreaOfCircle();
    // checkEvenOdd();
    // Factorial();
    // CheckPrime();
    // PrintPrimeFromOneToN(100);
    // ReverseInteger(123);
    // ReverseInteger(-123);
    // ReverseInteger(120);
    // SetKthBit(10,2);
    // SetKthBit(15,3);
    // ConvertTemperature(101.23);
    // ConvertTemperature(39.86);
    // countSetBits();
    CreateNumberUsingDigits();

    return 0;
}