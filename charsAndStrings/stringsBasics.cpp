#include<iostream>
using namespace std;

void stringsinit(){

    // Strings creation
    string str;

    // cout << "Enter string" << endl;
    // cin >> str;
    // cout << str << endl;
    // cout << str[0] << endl;

    // using pushback
    // str.push_back('l');
    // str.push_back('o');
    // str.push_back('v');
    // str.push_back('e');
    // cout << str << endl;

    // //using popback
    // str.pop_back();
    // cout << str << endl;

    // sentence and using delimiters

    // string sentence;
    // //cin >> sentence;
    // getline(cin, sentence, '\n');                     // cin.getline(arr,100); is used for char array only
    // cout << sentence << endl;

    // String Functions
    string name = "Mike November";

    // cout << name[0] << endl;
    // cout << name.at(0) << endl;

    // cout << name.front() << endl;
    // cout << name.back() << endl;
    // cout << name.length() << endl;

    // traversing using iterator
    // auto it = name.begin();
    // while (it != name.end()){
    //     cout << *it << " ";
    //     it++;
    // }
    // cout << endl;

    // checking for empty string

    // // name.clear();         //To clear the string - will get string as empty
    // if(name.empty()){
    //     cout << "String is empty" << endl;
    // }
    // else{
    //     cout << "String is not empty" << endl;
    // }

    // Append or Concatenate to string
    // string fName = "Mike";
    // string lName = "December";

    // string ans = fName + " " + lName;
    // cout << ans << endl;

    // Substrings

    // cout << name.substr(0,5);           // where 0 is position and 5 is length. Includes space as well

    // position and upto len
    // cout << name.substr(5,6);          // 5 is 5th index position and 6 is length
    // cout << name.substr(0) << endl;       // prints all from 0th index position
    // cout << name.substr(5);               // prints all from 5th index position

    // Finding in String
    // string name1 = "Mike December";
    // string word = "December";
    // int ans = name1.find(word);
    // cout << ans << endl;                   // found at 5th index

    // Alternate way to find in string
    // if(name.find(word) != string::npos) {
    //     //cout << "found";
    // }
    // else {
    //     //cout << "Not found";
    // }

    // String Comparison
    string s1 = "mike";
    string s2 = "mike";

    cout << s1.compare(s2) << endl;        // returns 0 if true else -1
}

int main(){
    stringsinit();
    return 0;
}