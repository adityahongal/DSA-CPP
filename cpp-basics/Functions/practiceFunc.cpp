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

void Factorial(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    long long int fact = 1;
    for ( int i = 1; i <= n; i++){
        fact = fact * i;
        cout << fact << endl;
    }
}

int main(){

    // KMtoMiles();
    // printAllDigits();
    // AreaOfCircle();
    // checkEvenOdd();
    Factorial();

    return 0;
}