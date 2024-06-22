#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// Remove all adjacent duplicates in a string
// leetcode ques 1047

// You are given a string s consisting of lowercase English letters. A duplicate
// removal consists of choosing two adjacent and equal letters and removing
// them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It
// can be proven that the answer is unique.

// Example 1:

// Input: s = "abbaca"
// Output: "ca"
// Explanation:
// For example, in "abbaca" we could remove "bb" since the letters are adjacent
// and equal, and this is the only possible move.  The result of this move is
// that the string is "aaca", of which only "aa" is possible, so the final
// string is "ca". Example 2:

// Input: s = "azxxzy"
// Output: "ay"

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.

void removeAdjacentDuplicateStrings(string str){
    string ans = "";
    int n = str.length();

    for(int i = 0; i < n; i++){
        char currentCharacter = str[i];
        if(ans.empty() || currentCharacter != ans.back()){
            ans.push_back(currentCharacter);
        }
        else if(currentCharacter == ans.back()){
            ans.pop_back();
        }
    }
    // return ans;
    cout << "Answer is: " << ans << endl;    
}

int main(){
    removeAdjacentDuplicateStrings("abbaca");
    removeAdjacentDuplicateStrings("azxxzy");
    return 0;
}