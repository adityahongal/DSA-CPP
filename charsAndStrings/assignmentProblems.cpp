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

// Leetcode 12: Integer to Roman
void intToRoman(int num) {
    string romanSymbols[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                            "XL", "X",  "IX", "V",  "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string answer = "";
    for (int i = 0; i < 13; i++) {
      while (num >= values[i]) {             //since we are going larger to smaller
        answer += romanSymbols[i];
        num -= values[i];
      }
    }
    cout << "Answer " << answer << endl;
}

// Leetcode 6. Zigzag Conversion
void convert(string s, int numRows) {
    if (numRows == 1) {                          //If there is only 1 row or 1 character
      cout << "Answer: " << s << endl;
      return;
    }

    int i = 0;
    int row = 0;
    bool direction = 1; // 1 -> Top to bottom 0 -> vice versa
    vector< string > zigzag(numRows);

    while (true) {
      if (direction) {
        // T -> B
        while (row < numRows && i < s.size()) {               // out of range check and iterate thru all rows given
            zigzag[row++].push_back(s[i++]);
        }

        row = numRows - 2;                                // once the T->B conversion is done we need to be at a B->T row
      } 
      else {
        // starting from zigzagrow to zero B->T
        while (row >= 0 && i < s.size()) {
          zigzag[row--].push_back(s[i++]);
        }
        row = 1;                                         // we need not to be at zero to T->B
      }

      if (i >= s.size())
        break;                                            // break if all chars in string are iterated
      direction = !direction;                            // update direction after operation is completed
    }                                                    // End of while loop

    cout << "Answer: ";
    for (int k = 0; k < zigzag.size(); k++) {
      cout << zigzag[k];
    }
    cout << endl;
}

static bool comparator(string a, string b) {
    string t1 = a + b;
    string t2 = b + a;

    return t1 > t2;
}

void largestNumber(vector< int > &nums) {
    vector< string > snums;

    for (auto n : nums) {
      snums.push_back(to_string(n));                 // Converting to string
    }

    sort(snums.begin(), snums.end(), comparator);    // sort and custom comparator

    string answer = "";
    
    if (snums[0] == "0") {                           // Handle edge case when all numbers are 0
      cout << "0" << endl;
      return;
    }
    
    for (auto str : snums) {                        // Join the sorted strings to form the largest number
      answer += str;
    }

    cout << answer << endl;
}

// Leetcode 2125. Number of Laser Beams in a Bank
// TC O(n^2)

// There is one laser beam between any two security devices if both conditions are met:

// 1. The two devices are located on two different rows: r1 and r2, where r1 < r2.
// 2.For each row i where r1 < i < r2, there are no security devices in the ith row.

int countDevices(string &binary) {                 // To count no. of 1's i.e. devices
    int count = 0;
    for(auto b:binary) {
      count += b - '0';
    }
    return count;
}

int numberOfBeams(vector< string > &bank) {
    vector<int> devices;
    for(auto row: bank) {
        devices.push_back(countDevices(row));      // Storing the count of devices
    }

    int beams = 0;
    for(int i=0; i<devices.size(); i++) {
      int j = i+1;
      while(j < devices.size()) {
          beams += devices[i] * devices[j];
          if(devices[j] == 0) {                   
              j++;
          } 
          else {
              break;                              // This satisfies condition 2 in Question
          }
      }
    }

    return beams;
}

// Leetcode 539. Minimum Time Difference
// Given a list of 24-hour clock time points in "HH:MM" format, return the
// minimum minutes difference between any two time-points in the list.
// Example 1:

// Input: timePoints = ["23:59","00:00"]
// Output: 1

// Example 2:

// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0

int convertToMins(string time) {
    int hour = stoi(time.substr(0, 2));              // inbuilt stoi to convert string to integer
    int mins = stoi(time.substr(3, 2));              // substr - to get substring(index,length)
    return 60 * hour + mins;
}
int findMinimumTimeDifference(vector< string > &timePoints) {
  // substr() -> fetch hrs and min strings
  // stoi() -> string to integer conversion
  // total minutes
  // sort
  // EDGE CASE ->

  // min = 60 * HH + MM

    vector< int > mins;
    for (auto time : timePoints) {
      mins.push_back(convertToMins(time));
    }
    sort(mins.begin(), mins.end());

    // calculate minimum difference
    int answer = INT_MAX;                                   // stores minimum differnce
    for (int i = 0; i < mins.size() - 1; ++i) {
      answer = min(answer, mins[i + 1] - mins[i]);
    }

    // last hour difference
    int lastDiff = mins[0] + 1440 - mins[mins.size() - 1];
    answer = min(answer, lastDiff);

    return answer;
}

// Leetcode 1209. Remove All Adjacent Duplicates in String II

// Method 1 TC - O(NK). More Run time since we don't use any space
bool areLastK_1CharsSame(string &ans, char &newch, int K_1) {
  int it = ans.size() - 1;
  for (int k = 0; k < K_1; k++) {
    if (newch != ans[it]) {
      return false;
    }
    it--;
  }
  return true;
}
string removeDuplicatesMethodOne(string s, int k) {
  string ans;
  for (int i = 0; i < s.size(); ++i) {
    char &newchar = s[i];
    if (ans.size() < k - 1) {
      ans.push_back(newchar);
    } else {
      if (areLastK_1CharsSame(ans, newchar, k - 1)) {
        for (int j = 0; j < k - 1; j++) {
          ans.pop_back();
        }
      } else {
        ans.push_back(newchar);
      }
    }
  }
  return ans;
}

// Method 2
// 2 pointer approach TC - O(n) SC - O(n)
// Less runtime and more efficient
string removeDuplicatesMethodTwo(string s, int k) {
    int i = 0, j = 0;
    vector< int > count(s.size(), 0);        // SINGLE SPACE  

    while (j < s.size()) {
      s[i] = s[j];
      count[i] = 1;                          // set count to 1
      if (i > 0 && s[i] == s[i - 1]) {
        count[i] += count[i - 1];
      }
      if (count[i] == k) {
        i -= k;
      }
      ++i;
      ++j;
    }

    return s.substr(0, i);                  // since we are making changes inside string only
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
    // vector< char > testCaseOne;
    // vector< char > testCaseTwo;
    // vector< char > testCaseThree;

    // testCaseOne.push_back('a');
    // testCaseOne.push_back('a');
    // testCaseOne.push_back('b');
    // testCaseOne.push_back('b');
    // testCaseOne.push_back('c');
    // testCaseOne.push_back('c');
    // testCaseOne.push_back('c');

    // testCaseTwo.push_back('a');

    // testCaseThree.push_back('a');
    // testCaseThree.push_back('b');
    // testCaseThree.push_back('b');
    // testCaseThree.push_back('b');
    // testCaseThree.push_back('b');
    // testCaseThree.push_back('b');
    // testCaseThree.push_back('b');
    // testCaseThree.push_back('b');
    // testCaseThree.push_back('b');
    // testCaseThree.push_back('b');
    // testCaseThree.push_back('b');
    // testCaseThree.push_back('b');
    // testCaseThree.push_back('b');

    // int res1 = compress(testCaseOne);
    // print1DCharVector(testCaseOne);
    // cout << "Result: " << res1 << endl;

    // int res2 = compress(testCaseTwo);
    // print1DCharVector(testCaseTwo);
    // cout << "Result: " << res2 << endl;

    // int res3 = compress(testCaseThree);
    // print1DCharVector(testCaseThree);
    // cout << "Result: " << res3 << endl;

    // intToRoman(3749);
    // intToRoman(58);
    // intToRoman(1994);
    // intToRoman(1997);

    // convert("PAYPALISHIRING", 3);
    // convert("PAYPALISHIRING", 4);
    // convert("A", 1);

    // for largest number
    // vector< int > numsTestCaseOne;
    // vector< int > numsTestCaseTwo;
    // vector< int > numsTestCaseThree;

    // numsTestCaseOne.push_back(10);
    // numsTestCaseOne.push_back(2);

    // numsTestCaseTwo.push_back(3);
    // numsTestCaseTwo.push_back(30);
    // numsTestCaseTwo.push_back(34);
    // numsTestCaseTwo.push_back(5);
    // numsTestCaseTwo.push_back(9);

    // numsTestCaseThree.push_back(0);
    // numsTestCaseThree.push_back(0);

    // largestNumber(numsTestCaseOne);
    // largestNumber(numsTestCaseTwo);
    // largestNumber(numsTestCaseThree);

    // for Laser beams
    // vector< string > testCaseOne;
    // vector< string > testCaseTwo;

    // testCaseOne.push_back("011001");
    // testCaseOne.push_back("000000");
    // testCaseOne.push_back("010100");
    // testCaseOne.push_back("001000");

    // testCaseTwo.push_back("000");
    // testCaseTwo.push_back("111");
    // testCaseTwo.push_back("000");

    // cout << "Total No of laser beams are: " << numberOfBeams(testCaseOne) << endl;
    // cout << "Total No of laser beams are: " << numberOfBeams(testCaseTwo) << endl;

    // For find minimm time difference
    // vector< string > timePointsTestCaseOne;
    // vector< string > timePointsTestCaseTwo;
    // vector< string > timePointsTestCaseThree;

    // timePointsTestCaseOne.push_back("23:59");
    // timePointsTestCaseOne.push_back("00:00");

    // timePointsTestCaseTwo.push_back("00:00");
    // timePointsTestCaseTwo.push_back("23:59");
    // timePointsTestCaseTwo.push_back("00:00");

    // timePointsTestCaseThree.push_back("12:12");
    // timePointsTestCaseThree.push_back("00:13");

    // cout << findMinimumTimeDifference(timePointsTestCaseOne) << endl;

    // cout << findMinimumTimeDifference(timePointsTestCaseTwo) << endl;

    // cout << findMinimumTimeDifference(timePointsTestCaseThree) << endl;

    // cout << removeDuplicatesMethodOne("deeedbbcccbdaa", 3) << endl;
    // cout << removeDuplicatesMethodOne("abcd", 2) << endl;
    // cout << removeDuplicatesMethodOne("pbbcggttciiippooaais", 2) << endl;

    cout << removeDuplicatesMethodTwo("deeedbbcccbdaa", 3) << endl;
    cout << removeDuplicatesMethodTwo("abcd", 2) << endl;
    cout << removeDuplicatesMethodTwo("pbbcggttciiippooaais", 2) << endl;
    return 0;
}