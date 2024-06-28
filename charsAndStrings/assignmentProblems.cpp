#include <climits>
#include <ctype.h>
#include <iostream>
#include <map>
#include <string.h>
#include <string>
#include <vector>
#include <array>             //used for group anagram method 2
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

// Leetcode 767. Reorganize String
// T.C. => O(N)
// Greedy algorithm/Method
void reorganizeString(string s) {
  int hash[26] = {0};

  for (int i = 0; i < s.size(); i++) {
    hash[s[i] - 'a']++;                         //mapping from 0 to 26
  }

  // find most freq char
  char maxFreqChar;                             //this will hold most appearing characters
  int maxFreq = INT_MIN;
  for (int i = 0; i < 26; i++) {
    if (hash[i] > maxFreq) {
      maxFreq = hash[i];
      maxFreqChar = i + 'a';                    // if i=0, i+a=0+97=>a. if i=1, i+a=1+97=>b
    }
  }

  // try to place most freq char
  int index = 0;
  while (maxFreq > 0 && index < s.size()) {
    s[index] = maxFreqChar;
    maxFreq--;
    index += 2;
  }

  // one or more max freq char was not able to place adacently or goes out of bound
  if (maxFreq != 0) {
    cout << "Answer: " << "" << endl;
    return;
  }

  hash[maxFreqChar - 'a'] = 0;                  // set most freq char to zero after its placed

  // To place the rest of char
  for (int i = 0; i < 26; i++) {
    while (hash[i] > 0) {
      // if index goes out of string range(s.size()) while placing,bring it back to index 1
      // or else continue till s.size() is reached
      index = index >= s.size() ? 1 : index;
      s[index] = i + 'a';
      index += 2;
      hash[i]--; // reduce frequency of char after placing
    }
  }

  cout << "Answer: " << s << endl;
}

// Leetcode 49 Group Anagrams
// TC (for method 1):-
// N -> strs.length
// K -> max length of largest string
// O(N KlogK) -> KlogK is TC of map datastructure insert
// SC => O(NK)   

// Method 1 -  using sorting and Mapping

void groupAnagrams(vector< string > &strs) {
  // map string -> vector answer
    map< string, vector< string > > mp;
    for (auto str : strs) {
      string s = str;
      sort(s.begin(), s.end());
      mp[s].push_back(str);
    }

    vector< vector< string > > answer;
    for (auto it = mp.begin(); it != mp.end(); it++) {
      answer.push_back(it->second); // key -> first, vector<string> (i.e value) -> second
    }

    print2DStringVector(answer);
}

// Method 2 - using hashing T.C.-> O(NK) S.C.-> O(NK)
array< int, 256 > hashStr(string s) {                        // Use #include <array>
  array< int, 256 > hashArray = {0};
  for (int i = 0; i < s.size(); i++) {
    hashArray[s[i]]++;
  }
  return hashArray;
}

void groupAnagram2(vector< string > &strs) {
  map< array< int, 256 >, vector< string > > mp;
  for (auto str : strs) {
    mp[hashStr(str)].push_back(str);
  }
  vector< vector< string > > answer;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    answer.push_back(it->second); // key -> first, vector<string>
  }
  print2DStringVector(answer);
}

// Leetcode 5 Longest Palindromic substring
// substrings of a string
// extract palidromic ones
// max length string from palindromic ones

bool checkPalindrome(string str, int start, int end) {
  while (start <= end) {
    if (str[start] == str[end]) {
      start++;
      end--;
    } else {
      return false;
    }
  }

  return true;
}
void longestPalindrome(string s) {
  string answer = "";
  for (int i = 0; i < s.size(); i++) {
    for (int j = i; j < s.size(); j++) {
      if (checkPalindrome(s, i, j)) {
        string t = s.substr(i, j - i + 1);
        answer = t.size() > answer.size() ? t : answer;
      }
    }
  }
  cout << answer << endl;
}

// leetcode 28. Find the Index of the First Occurrence in a String 
// T.C. -> O(mn)

int strStr(string haystack, string needle) {
  int sizeOfHaystack = haystack.size();               // n
  int sizeOfNeedle = needle.size();                   // m

  for (int i = 0; i <= sizeOfHaystack - sizeOfNeedle; i++) {           //n-m => to prevent i from going out of bound
    for (int j = 0; j < sizeOfNeedle; j++) {
      if (needle[j] != haystack[i + j]) {
        break;
      }

      if (j == sizeOfNeedle - 1) {                                 //matched
        return i;
      }
    }
  }

  return -1;
}

// Leetcode 8. String to Integer (atoi)
void myAtoi(string s) {

    // int integer = atoi(s.c_str());
    // cout << "Answer using In built Library " << integer << endl;

    int num = 0, i = 0, sign = 1; // sign can be +1(+ve) and  -1(-ve)

    // iterate through leading whitespaces
    while (s[i] == ' ') {
      i++;
    }

    // check if it starts with + or - sign  
    if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
      sign = s[i] == '+' ? 1 : -1;
      ++i;
    }

    // To determine if its a digit and convert to integer
    while (i < s.size() && isdigit(s[i])) {
      if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')) {             //handling out of bound
        cout << "Answer: " << (sign == -1 ? INT_MIN : INT_MAX) << endl;
        return;
      }
      num = num * 10 + (s[i] - '0');                      // Converting to integer. ASCII of 0=48,1=49,2=50
      i++;
    }

    cout << "Answer: " << num * sign << endl;
    return;
}

// Leetcode 443. String Compression
// this algo is also called Running length Encoding algo

int compress(vector< char > &s) {
    int index = 0;
    int count = 1;
    char prev = s[0];

    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == prev) {
        count++;
      } else {
        s[index++] = prev;
        if (count > 1) {
          int start = index;
          while (count) {
            s[index++] = (count % 10) + '0';                 //if its greater than 1 or 2 digits we convert it to character
            count /= 10;
          }
          reverse(s.begin() + start, s.begin() + index);    //After converting to character we have to reverse it to get final
        }
        prev = s[i];
        count = 1;                                        //we reset it back to 1
      }
    }

  // To handle last character when i goes out of loop/bound (After For Loop)
  // We add it and return index
    s[index++] = prev;
    if (count > 1) {
      int start = index;

      while (count) {
        s[index++] = (count % 10) + '0';
        count /= 10;
      }
      reverse(s.begin() + start, s.begin() + index);
    }

    return index;
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

    // isIsomorphic("egg", "add");
    // isIsomorphic("paper", "title");
    // isIsomorphic("foo", "bar");

    // reorganizeString("aab");
    // reorganizeString("aaab");
    // reorganizeString("aaabc");

    // for group anagrams
    // vector< string > strs;
    // strs.push_back("eat");
    // strs.push_back("tea");
    // strs.push_back("tan");
    // strs.push_back("ate");
    // strs.push_back("nat");
    // strs.push_back("bat");

    // groupAnagrams(strs);
    // groupAnagram2(strs);

    // longestPalindrome("babad");
    // longestPalindrome("cbbd");

    // to find index of First Occurrence in a String
    // cout << strStr("sadbutsad", "sad") << endl;
    // cout << strStr("sadbutsad", "but") << endl;
    // cout << strStr("sadbutsada", "da") << endl;
    // cout << strStr("leetcode", "leeto") << endl;

    // myAtoi("42");
    // myAtoi(" -042");
    // myAtoi("1337c0d3");
    // myAtoi("0-1");
    // myAtoi("words and 987");

    // for string compression
    vector< char > testCaseOne;
    vector< char > testCaseTwo;
    vector< char > testCaseThree;

    testCaseOne.push_back('a');
    testCaseOne.push_back('a');
    testCaseOne.push_back('b');
    testCaseOne.push_back('b');
    testCaseOne.push_back('c');
    testCaseOne.push_back('c');
    testCaseOne.push_back('c');

    testCaseTwo.push_back('a');

    testCaseThree.push_back('a');
    testCaseThree.push_back('b');
    testCaseThree.push_back('b');
    testCaseThree.push_back('b');
    testCaseThree.push_back('b');
    testCaseThree.push_back('b');
    testCaseThree.push_back('b');
    testCaseThree.push_back('b');
    testCaseThree.push_back('b');
    testCaseThree.push_back('b');
    testCaseThree.push_back('b');
    testCaseThree.push_back('b');
    testCaseThree.push_back('b');

    int res1 = compress(testCaseOne);
    print1DCharVector(testCaseOne);
    cout << "Result: " << res1 << endl;

    int res2 = compress(testCaseTwo);
    print1DCharVector(testCaseTwo);
    cout << "Result: " << res2 << endl;

    int res3 = compress(testCaseThree);
    print1DCharVector(testCaseThree);
    cout << "Result: " << res3 << endl;
    return 0;
}