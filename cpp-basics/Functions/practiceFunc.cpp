#include<iostream>
using namespace std;

// Kilometer to Miles
void KMtoMiles(){
    float km;
    cout << "Enter Kilometer: ";
    cin >> km;
    float _1km = 0.621371;
    float miles = km * _1km;
    cout << km << " Kilometer = " << miles << " Miles" << endl;
}

int main(){

    KMtoMiles();
    
    return 0;
}