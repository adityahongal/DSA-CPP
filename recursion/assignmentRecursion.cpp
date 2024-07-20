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

// Leetcode 415. Add Strings
// N = max(num1, num2)
// m = constant
// TC O(N + 1) -> O(N)
// SC O(m(N+1)) -> O(N)
// take by ref(&num1,&num2) parameters to reduce space complexity
void addStrings(string &num1, int ptr1, string &num2, int ptr2, string &ans,
                int carry = 0) {
    
    if (ptr1 < 0 && ptr2 < 0) {
        // extra carry might be remaining
        if (carry != 0) {
        // return string(1, carry + '0');
        ans.push_back(carry + '0');
        }
        // return "";
        return;
    }

    // ex sum ptr1 is at 4 in 456 and sum2 56 -> ptr2 will be at diff positions
    // i.e. Extract digits or treat as '0' if pointer is below zero

    // string ans = "";
    
    int digitOfNum1 = (ptr1 >= 0 ? num1[ptr1] : '0') - '0';
    int digitOfNum2 = (ptr2 >= 0 ? num2[ptr2] : '0') - '0';
    int csum = digitOfNum1 + digitOfNum2 + carry;

    int remainingDigit = csum % 10;
    carry = csum / 10;
    ans.push_back(remainingDigit + '0');

    // ans += addStrings(num1, ptr1 - 1, num2, ptr2 - 1, ans, carry);
    addStrings(num1, ptr1 - 1, num2, ptr2 - 1, ans, carry);

    // return ans;
}

// Print all sub array using RE

// TC -> O(N^2)
// start run for N times
// end runs for N, N-1, N-2 ... 1 worst case N
// so N * N

// SC -> O(N)
// subarray runs -> N + 2 calls

void subArray_util(vector< int > &nums, int start, int end) {
    // base case
    if (end >= nums.size()) {
        return;
    }

    // processing
    for (int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    // RE Call
    subArray_util(nums, start, end + 1);
}

void subArray(vector< int > &nums) {                     
    for (int start = 0; start < nums.size(); start++) {        // To traverse start from 0th index to end of array
        int end = start;
        subArray_util(nums, start, end);
    }
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

    // // Check palindrome
    // string str1 = "racecar";
    // cout << checkPalindrome(str1, 0, str1.size() - 1) << endl;

    // string str2 = "racetar";
    // cout << checkPalindrome(str2, 0, str2.size() - 1) << endl;

    // for string add
    // string num1 = "456", num2 = "77";
    // string ans1 = "";
    // addStrings(num1, num1.size() - 1, num2, num2.size() - 1, ans1);
    // reverse(ans1.begin(), ans1.end());
    // cout << ans1 << endl;

    // string num3 = "9133", num4 = "0";
    // string ans2 = "";
    // addStrings(num3, num3.size() - 1, num4, num4.size() - 1, ans2);
    // reverse(ans2.begin(), ans2.end());
    // cout << ans2 << endl;

    // Print all subarray
    vector< int > nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    subArray(nums);
}