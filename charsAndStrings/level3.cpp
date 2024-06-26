#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>            // use for unordered_map
using namespace std;

void printStringVectorNativeMethod(vector<string> v) {
  // for each loop
  for (auto it : v) {
    cout << it << " ";
  }
  cout << endl;

}

// leetcode 2325 Decode the message
void createMapping(unordered_map<char,char> &mapping, string key) {
        char start = 'a';

        for(int i=0; i<key.length(); i++) {
            //if mapping is not already present , then create it 

            if(mapping.find(key[i]) == mapping.end()) {
                mapping[key[i]] = start;
                start++;
            }
        }

}

string useMapping(unordered_map<char,char> &mapping, string message) {
        string ans = "";
        for(int i=0; i<message.length(); i++) {
            char mappedCharacter = mapping[message[i]];
            ans.push_back(mappedCharacter);
        }
        return ans;
}
string decodeMessage(string key, string message) {
        //step1: create mapping
        unordered_map<char,char> mapping;
        char spaceCharacter = ' ';
        mapping[spaceCharacter] = spaceCharacter;

        createMapping(mapping, key);

        //step2: use mapping and decode msg
        string answer = useMapping(mapping, message);
        // return answer;

        cout << "Decoded message for the key: " << key << endl;
        cout << "is :- " << answer << endl;
}

// leetcode 2391 Minimum Amount of Time to Collect Garbage

void garbageCollection(vector< string > &garbage, vector< int > &travel) {

    int pickTimeP = 0;
    int pickTimeM = 0;
    int pickTimeG = 0;

    int travelTimeP = 0;
    int travelTimeM = 0;
    int travelTimeG = 0;

    int lastPositionP = 0;
    int lastPositionM = 0;
    int lastPositionG = 0;

    // calculate pick time
    // let's travel to the street of houses
    for (int i = 0; i < garbage.size(); i++) {
        string curr = garbage[i];
        //let dive in into current house and see the type of garbage present
        for (int j = 0; j < curr.length(); j++) {
        char ch = curr[j];
        if (ch == 'P') {
            pickTimeP++;
            lastPositionP = i;
        } else if (ch == 'G') {
            pickTimeG++;
            lastPositionG = i;

        } else if (ch == 'M') {
            pickTimeM++;
            lastPositionM = i;
        }
        }
    }

    // calculate travel time
    for (int i = 0; i < lastPositionP; i++) {
        travelTimeP += travel[i];
    }
    for (int i = 0; i < lastPositionG; i++) {
        travelTimeG += travel[i];
    }
    for (int i = 0; i < lastPositionM; i++) {
        travelTimeM += travel[i];
    }

    int answer = (pickTimeP + travelTimeP) + (pickTimeG + travelTimeG) +
                (pickTimeM + travelTimeM);
    cout << "Answer: " << answer << endl;
}

// leetcode 791 Custom sort string

static string orderCopy;               //we used this as global variable
static bool compare(char char1, char char2) {
    //logic ->
        //order wali string me dekho, k konsa character pehle 
        //aana chahiye and konsa character baad me aana chahaiye

        //true -> a will be placed before b
        //false -> b will be placed before a 

    return (orderCopy.find(char1) < orderCopy.find(char2));
}

void customSortString(string order, string s) {
    orderCopy = order;
    sort(s.begin(), s.end(), compare);             // custom comparator. 

    cout << s << endl;
}

// Leetcode 890
// Find and replace Pattern
void normalise(string &str) {
        char start = 'a';
        unordered_map<char,char> mapping;

        for(int i=0; i<str.length(); i++) {
            char stringKaCharacter = str[i];
            if(mapping.find(stringKaCharacter) == mapping.end()) {
                //if mapping pehle se present nahi h 
                //then create it and move ahead
                mapping[stringKaCharacter] = start;
                start++;
            }
        }

        //mapping create ho chuki h 
        //string str ko update normalise kardo using mapping 
        for(int i=0; i<str.length(); i++) {
            char mappedCharacter = mapping[str[i]];            //example of matching d->a , e->b , q->c
            str[i] = mappedCharacter;
        }
        //toh humne str wali string ko normalise / update krdia 
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans ;

        //step A: pattern normalise 
        normalise(pattern);
        ///stepB: words ki list me hr ek word ko normlaise 
        // karna hai, and compare krna h pattern se
        //if pattern k equal aagya, toh ans me store krna h 
        for(int i=0; i<words.size(); i++) {
            //ith string 
            string currWord = words[i];
            normalise(currWord);
            if(currWord == pattern) {
                ans.push_back(words[i]);
            }
        }
        printStringVectorNativeMethod(ans);
        return ans;
}

int main(){
    // decodeMessage("the quick brown fox jumps over the lazy dog","vkbs bs t suepuv");
    // decodeMessage("eljuxhpwnyrdgtqkviszcfmabo","zwx hnfx lqantp mnoeius ycgk vcnjrdb");

    // // for garbage collection problem,
    // vector< string > garbageTestCaseOne;
    // vector< int > travelTestCaseOne;
    // vector< string > garbageTestCaseTwo;
    // vector< int > travelTestCaseTwo;

    // garbageTestCaseOne.push_back("G");
    // garbageTestCaseOne.push_back("P");
    // garbageTestCaseOne.push_back("GP");
    // garbageTestCaseOne.push_back("GG");

    // travelTestCaseOne.push_back(2);
    // travelTestCaseOne.push_back(4);
    // travelTestCaseOne.push_back(3);

    // garbageTestCaseTwo.push_back("MMM");
    // garbageTestCaseTwo.push_back("PGM");
    // garbageTestCaseTwo.push_back("GP");

    // travelTestCaseTwo.push_back(3);
    // travelTestCaseTwo.push_back(10);

    // garbageCollection(garbageTestCaseOne, travelTestCaseOne);
    // garbageCollection(garbageTestCaseTwo, travelTestCaseTwo);

    // customSortString("cba", "abcd");
    // customSortString("bcafg", "abcd");

    // for find and replace pattern
    vector< string > wordsTestCaseOne;
    string patternTestCaseOne = "abb";

    wordsTestCaseOne.push_back("abc");
    wordsTestCaseOne.push_back("deq");
    wordsTestCaseOne.push_back("mee");
    wordsTestCaseOne.push_back("aqq");
    wordsTestCaseOne.push_back("dkd");
    wordsTestCaseOne.push_back("ccc");

    vector< string > wordsTestCaseTwo;
    string patternTestCaseTwo = "a";

    wordsTestCaseTwo.push_back("a");
    wordsTestCaseTwo.push_back("b");
    wordsTestCaseTwo.push_back("c");

    findAndReplacePattern(wordsTestCaseOne, patternTestCaseOne);
    findAndReplacePattern(wordsTestCaseTwo, patternTestCaseTwo);

    return 0;
}