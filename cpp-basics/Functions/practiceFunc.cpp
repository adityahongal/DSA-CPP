#include<iostream>
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

int ReverseInteger(int x) {
  int ans = 0 ;
  bool isNeg = false; 

  if ( x <= INT_MIN){
    return 0;
  }

  if (x < 0) {
    isNeg = true;
    x = -x;
  }

  while (x > 0) {
    
    if ( ans > INT_MAX/10 ){
      return 0;
    }

    int digit = x % 10;
    ans = ans * 10 + digit;
    x = x / 10;
  }
  cout << (isNeg ? -ans : ans) << endl;
}

int main(){

    // KMtoMiles();
    // printAllDigits();
    // AreaOfCircle();
    // checkEvenOdd();
    // Factorial();
    // CheckPrime();
    // PrintPrimeFromOneToN(100);
    ReverseInteger(123);
    ReverseInteger(-123);
    ReverseInteger(120);

    return 0;
}