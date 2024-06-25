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

int main(){
    decodeMessage("the quick brown fox jumps over the lazy dog","vkbs bs t suepuv");
    decodeMessage("eljuxhpwnyrdgtqkviszcfmabo","zwx hnfx lqantp mnoeius ycgk vcnjrdb");
    return 0;
}