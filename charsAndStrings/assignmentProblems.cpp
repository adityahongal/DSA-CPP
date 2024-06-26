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

// Leetcode 917 reverse only letters - T.C. = O(n)
void reverseOnlyLetters(string str) {
    int low = 0, high = str.size() - 1;
    while (low < high) {
      if (isalpha(str[low]) && isalpha(str[high])) {
        swap(str[low], str[high]);
        low++;
        high--;
      } else if (!isalpha(str[low])) {
        low++;
      } else {
        high--;
      }
    }

    cout << "String after reverse: " << str << endl;
    return;
}

// Leetcode 14 find Longest Common prefix
void findLongestCommonPrefix(vector< string > &strs) {
    string answer = "";
    int i = 0;
    while (true) {
      char currentChar = 0;
      for (auto str : strs) {
        if (i >= str.size()) {                  // To check out of bound. "if(i >= str[i])" was used previously but it was giving error in leetcode but running in vscode
          currentChar = 0;
          break;
        }

        if (currentChar == 0) {                 // we check with char of all strings,if its common then add and update
          currentChar = str[i];
        } else if (str[i] != currentChar) {     // if its not same char or common prefix then we come back to 0 and break
          currentChar = 0;
          break;
        }
      }

      if (currentChar == 0) {                   // after a certain words in string if there are no letters present we exit
        break;                                  // eg. flower and flow, there are no letters after flow
      }

      answer.push_back(currentChar);            // push current character to answer
      i++;
    }

    if (answer == "") {
      cout << "No Prefix found" << endl;

    } else {
      cout << "Longest common prefix is: " << answer << endl;
    }
    return;
}

// Leetcode 345 reverse only vowels

bool isVowel(char ch) {
    ch = tolower(ch);                      // inbuilt STL to convert upper case to lower case
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
void reverseOnlyVowels(string str) {
    int low = 0, high = str.size() - 1;

    while (low < high) {
      if (isVowel(str[low]) && isVowel(str[high])) {
        swap(str[low], str[high]);
        low++;
        high--;
      } else if (!isVowel(str[low])) {
        low++;
      } else {
        high--;
      }
    }

  cout << "String after reverse: " << str << endl;
  return;
}

// leetcode 205 isomorphic strings

void createMappingAlphabetically(string &str) {
  // find mapping
  char start = 'a';
  char mapping[300] = {0};
  for (auto ch : str) {
    if (mapping[ch] == 0) {
        mapping[ch] = start;
        start++;
    }
  }

  // update string according to mapping
  for (int i = 0; i < str.length(); i++) {
      char ch = str[i];
      str[i] = mapping[ch];
  }
}

void isIsomorphic(string s, string t) {
    createMappingAlphabetically(s);
    createMappingAlphabetically(t);
    cout << (s == t) << " " << s << " " << t << " " << endl;
}

int main(){
    // isAnagram("anagram", "nagaram");
    // isAnagram("rat", "car");

    // isAnagramByFrequencyMethod("anagram", "nagaram");
    // isAnagramByFrequencyMethod("rat", "car");

    // reverseOnlyLetters("ab-cd");
    // reverseOnlyLetters("Test1ng-Leet=code-Q!");
    // reverseOnlyLetters("a-bC-dEf-ghIj");

    // for longest prefix problem
    // vector< string > strsTestCaseOne;
    // vector< string > strsTestCaseTwo;

    // strsTestCaseOne.push_back("flower");
    // strsTestCaseOne.push_back("flow");
    // strsTestCaseOne.push_back("flight");

    // strsTestCaseTwo.push_back("dog");
    // strsTestCaseTwo.push_back("racecar");
    // strsTestCaseTwo.push_back("car");

    // findLongestCommonPrefix(strsTestCaseOne);
    // findLongestCommonPrefix(strsTestCaseTwo);

    // reverseOnlyVowels("hello");
    // reverseOnlyVowels("LeetCode");

    isIsomorphic("egg", "add");
    isIsomorphic("paper", "title");
    isIsomorphic("foo", "bar");
    return 0;
}