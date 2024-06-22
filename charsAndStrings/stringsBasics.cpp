#include<iostream>
using namespace std;

void stringsinit(){

    // Strings creation
    string str;

    // cout << "Enter string" << endl;
    // cin >> str;
    // cout << str << endl;
    // cout << str[0] << endl;

    //using pushback
    str.push_back('l');
    str.push_back('o');
    str.push_back('v');
    str.push_back('e');
    cout << str << endl;

    //using popback
    str.pop_back();
    cout << str << endl;
}

int main(){
    stringsinit();
    return 0;
}