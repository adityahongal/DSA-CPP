#include <iostream>
using namespace std;

// gcd (a,b) = gcd (a-b, b) if a > b
// gcd (a,b) = gcd (b-a, a) if a < b
// Apply the above formula till one of the parameter becomes Zero and other parameter is the Answer

// gcd(a,b) = gcd (a % b,b) a>b  This is also cab be used but we don't use this since it consumes more time

int gcd(int A, int B) {
    if (A == 0) {
        return B;
    }
    if (B == 0) {
        return A;
    }

    while (A > 0 && B > 0) {
        if (A > B) {
            A = A - B;
        } 
        else {
            B = B - A;
        }
    }

    return A == 0 ? B : A;
}

int main() {
    cout << "Euclid Approach HCF: " << gcd(24, 72) << endl;
    cout << "Euclid Approach HCF: " << gcd(3, 6) << endl;
    return 0;
}
