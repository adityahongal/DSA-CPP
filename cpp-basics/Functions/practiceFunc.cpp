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
bool CheckPrime() {
  // divisible by one or self only.
  // not perfectly divisible by other numbers

  // method to solve
  // we will not check divisibility with self and 1
  // we will check with all the other numbers that in the range of
  // 2 to N-1,
  // where N is the number you are checking prime for,
  // 2 is to skip 1 and N-1 is to skip the number you are checking

  int num;
  cout << "Enter a number: ";
  cin >> num;

  bool isPrime = true;  // Flag to track if the number is prime

  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      isPrime = false;
      break;  // Exit the loop if not prime
    }
  }

  if (isPrime) {
    cout << num << " is a prime number" << endl;
  } else {
    cout << num << " is not a prime number" << endl;
  }

  return isPrime; // You can optionally return the primality result
}

int main(){

    // KMtoMiles();
    // printAllDigits();
    // AreaOfCircle();
    // checkEvenOdd();
    // Factorial();
    CheckPrime();

    return 0;
}