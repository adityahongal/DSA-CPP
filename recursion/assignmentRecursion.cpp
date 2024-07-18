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

int main(){

    // for last occurance of char
    // Method 1
    // int index = 0;
    // int ans = -1;
    // findLastOccuranceOfChar("abcddedg", index, ans, 'd');
    // cout << "Found on index: " << ans << endl;

    // last occr using inbuilt STL function
    const char* last_occurrence = strrchr("abcddedg", 'd');
    cout << "using inbuilt strrchr(): " << last_occurrence << endl;

    // for last occurance of char
    // Method 2
    string str = "abcddedg";
    int index = str.size() - 1;  // start from rightmost index (n-1)
    int ans = -1;
    findLastOccuranceOfCharRTL(str, index, ans, 'd');
    cout << "Found on index using RTL: " << ans << endl;
}