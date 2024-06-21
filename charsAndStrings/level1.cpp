#include<iostream>
using namespace std;

void initchars(){

    //Creation of character array
    char arr[100];

    //Taking input
    // Char array can take input all at once
    //But in int array we need to give inputs one by one
    //ending of char array will be a null character "\0"
    //it acts as terminator for that array
    
    cout << "Enter your name: " << endl;
    cin >> arr;

    //Printing character array
    cout << "Your name is: " << arr << endl;
}

int main(){
    initchars();
    return 0;
}