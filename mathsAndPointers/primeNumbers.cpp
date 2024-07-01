#include<iostream>
#include<vector>
#include <cmath>              // for square root function
using namespace std;

// Count Primes leetcode - 204
// naive approach
// TC = O(n) + O(n-1) = O(n^2) 
// this solution exceeds time limit on leetcode
bool isPrimeNaive(int n) {
    if(n <= 1) return false;
    for(int i= 2; i<n ;i++) {
        if(n % i == 0) {
        return false;
        }
    }
    return true;
}

int countPrimesNaive(int n) {
    int c = 0;
    for(int i=0; i< n; i++) {
        if(isPrimeNaive(i)) {
        ++c;
        }
    }
    return c;
}

// Using square root
// TC O(sqrt(n)) + O(n) = O(n sqrt(n))
// this solution too exceeds time limit on leetcode
bool isPrimeSQRT(int n) {
    if(n <= 1) return false;

    int sqrtN = sqrt(n);
    for(int i= 2; i<=sqrtN ;i++) {
        if(n % i == 0) {
        return false;
        }
    }
    return true;
}

int countPrimesSQRT(int n) {
    int c = 0;
    for(int i=0; i< n; i++) {
        if(isPrimeSQRT(i)) {
        ++c;
        }
    }
    return c;
}

int main(){

    cout << "Naive Approach: " << countPrimesNaive(10) << endl; 
    cout << "SQRT Approach: " << countPrimesSQRT(21) << endl;  
    
    return 0;
}