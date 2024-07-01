#include <iostream>
using namespace std;

// Modulo Arithmatic Basics

// consider (a % m) -> answer lies in the range [0,1,2....,m-1]

// Then generally to avoid overflow while storing in INT variable
// we do modulo with a large number
// we can derive basic formulas as below and use
// (a+b) % m = a % m + b % m
// (a-b) % m = a % m - b % m
// a % m = ((a % m) % m) % m
// (a * b) % m = a % m * b % m

// Fast Exponentation

// 1. Normal Solution A ^ B -> TC -> O(b)        // Slow
// soln -> loop from 0 -> B-1 and ans = ans * a
// 2. Better Solution A ^ B -> TC -> O(logb)     // Fast

// example 2 ^ 3 = 8
// example 2 ^ 5 = 32
// example 5 ^ 4 = 625

// O(power) = O(b)
int slowExponentiation(int num, int power) {
    int answer = 1;
    while (power--) {
        answer *= num;
    }

    return answer;
}

// O(log(power)) = O(log(b))
int fastExponentiation(int num, int power) {
    int answer = 1;
    while (power > 0) {
        if (power & 1) {                       // odd check using bitwise
        answer = answer * num;
        }

        num = num * num;
        power >>= 1; // divide by 2 or power = power/2 or b=b/2
    }

    return answer;
}

int main() {

    cout << slowExponentiation(2, 5) << endl;
    cout << slowExponentiation(5, 4) << endl;

    cout << fastExponentiation(2, 5) << endl;
    cout << fastExponentiation(5, 4) << endl;

    return 0;
}
