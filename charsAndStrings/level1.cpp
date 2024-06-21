#include<iostream>
#include <cstring> // For strlen
using namespace std;

// Finding length of char array

int getLength(char arr[], int size){
    int count = 0;

    // for(int i=0; i< size; i++) {
    //   if(ch[i] == '\0') {
    //     break;
    //   } else {
    //     count++;
    //   }
    // }

    int index = 0;
    while(arr[index] != '\0'){
        count++;
        index++;
    }
    return count;
}

void initchars(){

    //Creation of character array
    char arr[100];

    // Taking input

    // Char array can take input all at once
    // But in int array we need to give inputs one by one
    // ending of char array will be a null character "\0"
    // it acts as terminator for that array
    // Every characterhas its own ASCII value
    // The ASCII value of null is 0

    cout << "Enter your name: " << endl;
    // cin >> arr;

    // Taking inputs with spaces or new line is not possible
    // using cin
    // so we need to use our custom delimiter to handle this case
    // we use getline
    // Example Sentence type input

    // cin.getline(arr,100);
    // cin.getline(arr,100, '\t');        // Custom delimiter. Stops taking input when we hit tab

    //Printing character array
    cout << "Your name is: " << arr << endl;

    // Printing ASCII value of each character
    // We use typcasting to do that
    // enter 4 chars to verify null value

    // cout << arr[0] << " --> " << (int)arr[0] << endl;
    // cout << arr[1] << " --> " << (int)arr[1] << endl;
    // cout << arr[2] << " --> " << (int)arr[2] << endl;
    // cout << arr[3] << " --> " << (int)arr[3] << endl;
    // cout << arr[4] << " --> " << (int)arr[4] << endl;

    // Finding length of array call function
    cin >> arr;
    int len = getLength(arr,100);
    cout << "Length of your name is: " << len << endl;
}

// Replace the characters
void ReplaceCharacter(){
    char ch[1000];
    cout << "Enter your name with '@' characters" << endl;
    cin >> ch;
    cout << "Entered String is:" << ch << endl;
    
    int size = strlen(ch);                          // we cannot use ch.size(); for chars
    for(int i = 0; i < size; i++){
        if(ch[i] == '@'){
            ch[i] = ' ';
        }
    }
    cout << "Replaced String is:" << ch << endl;
}

int main(){
    // initchars();
    ReplaceCharacter();
    return 0;
}