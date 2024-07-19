#include <cstring> // for strrchr
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Last occurance of a char
// Method 1 - Search from Left to right recursively
void findLastOccuranceOfChar(string str, int index, int &ans, char target) {
    if (str[index] == '\0') {                    // Base Case
        return;
    }

    if (str[index] == target) {
        ans = index;
    }

    findLastOccuranceOfChar(str, index + 1, ans, target);     // recursive call
}

// Method 2 - Search from Right to left recursively
void findLastOccuranceOfCharRTL(string str, int index, int &ans, char target) {
    if (str[index] < 0 ) {                    // Base Case
        return;
    }

    if (str[index] == target) {
        ans = index;
        return;
    }

    findLastOccuranceOfCharRTL(str, index - 1, ans, target);     // recursive call // i = n-1
}

// Reverse a string recursively
// Tc -> O(n/2) -> O(n)
// SC -> O(n/2 + 1 ) -> O(n)
void reverseString(string &str, int start, int end) {
    if (start >= end) {
        return;
    }

    swap(str[start], str[end]);

    reverseString(str, start + 1, end - 1);
}

// Check palindrome
// 1 is for base condition below
// Tc -> O(n/2) -> O(n)
// SC -> O(n/2 + 1 ) -> O(n)

bool checkPalindrome(string &str, int start, int end) {
    if (start >= end) {
        return true;
    }

    if (str[start] != str[end]) {
        return false;
    }

    return checkPalindrome(str, start + 1, end - 1);
}


int main(){

    // for last occurance of char
    // Method 1
    // int index = 0;
    // int ans = -1;
    // findLastOccuranceOfChar("abcddedg", index, ans, 'd');
    // cout << "Found on index: " << ans << endl;

    // last occr using inbuilt STL function
    // const char* last_occurrence = strrchr("abcddedg", 'd');
    // cout << "using inbuilt strrchr(): " << last_occurrence << endl;

    // // for last occurance of char
    // // Method 2
    // string str = "abcddedg";
    // int index = str.size() - 1;  // start from rightmost index (n-1)
    // int ans = -1;
    // findLastOccuranceOfCharRTL(str, index, ans, 'd');
    // cout << "Found on index using RTL: " << ans << endl;

    // Reverse a string
    // string str = "hello";
    // int start = 0;
    // int end = str.length() - 1;
    // reverseString(str, start, end);
    // cout << str << endl;

    // Check palindrome
    string str1 = "racecar";
    cout << checkPalindrome(str1, 0, str1.size() - 1) << endl;

    string str2 = "racetar";
    cout << checkPalindrome(str2, 0, str2.size() - 1) << endl;
}