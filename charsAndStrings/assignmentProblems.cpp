#include <climits>
#include <ctype.h>
#include <iostream>
#include <map>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

void print2DStringVector(vector< vector< string > > arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  }
}

void print1DCharVector(vector< char > arr) {
  cout << "Print Char Vector" << endl;
  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << "  ";
  }
  cout << endl;
}

// Leetcode 242 Valid Anagram

void isAnagram(string str, string testString) {
    // method 1 sort and compare
    sort(str.begin(), str.end());
    sort(testString.begin(), testString.end());

    cout << (str == testString) << endl;
}

// method 2 using frequency table/hash table

void isAnagramByFrequencyMethod(string str, string testString) {
  int freqTable[256] = {0}; // ASCI range for all chars are 2^8 or 256 max

  for (int i = 0; i < str.size(); i++) {
    freqTable[str[i]]++;
  }

  for (int i = 0; i < testString.size(); i++) {
    freqTable[testString[i]]--;
  }

  for (int i = 0; i < 256; i++) {
    if (freqTable[i] != 0) {
      cout << "Not Anagram" << endl;
      return;
    }
  }

  cout << "It is an Anagram" << endl;
  return;
} // TC = O(m) + O(n) + O(256) = O(m+n)

int main(){
    // isAnagram("anagram", "nagaram");
    // isAnagram("rat", "car");

    isAnagramByFrequencyMethod("anagram", "nagaram");
    isAnagramByFrequencyMethod("rat", "car");
    return 0;
}