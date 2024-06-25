#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>            // use for unordered_map
using namespace std;

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

int main(){
    // decodeMessage("the quick brown fox jumps over the lazy dog","vkbs bs t suepuv");
    // decodeMessage("eljuxhpwnyrdgtqkviszcfmabo","zwx hnfx lqantp mnoeius ycgk vcnjrdb");

    // for garbage collection problem,
    vector< string > garbageTestCaseOne;
    vector< int > travelTestCaseOne;
    vector< string > garbageTestCaseTwo;
    vector< int > travelTestCaseTwo;

    garbageTestCaseOne.push_back("G");
    garbageTestCaseOne.push_back("P");
    garbageTestCaseOne.push_back("GP");
    garbageTestCaseOne.push_back("GG");

    travelTestCaseOne.push_back(2);
    travelTestCaseOne.push_back(4);
    travelTestCaseOne.push_back(3);

    garbageTestCaseTwo.push_back("MMM");
    garbageTestCaseTwo.push_back("PGM");
    garbageTestCaseTwo.push_back("GP");

    travelTestCaseTwo.push_back(3);
    travelTestCaseTwo.push_back(10);

    garbageCollection(garbageTestCaseOne, travelTestCaseOne);
    garbageCollection(garbageTestCaseTwo, travelTestCaseTwo);

    return 0;
}