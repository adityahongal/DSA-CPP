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

void AreaOfCircle(){
    float radius;
    cout << "Enter radius: ";
    cin >> radius;
    float area = 3.14 * radius * radius;
    cout << "Area of circle is: " << area << endl;
}

int main(){

    // KMtoMiles();
    // printAllDigits();
    AreaOfCircle();

    return 0;
}