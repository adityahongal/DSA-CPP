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

// Lower to Upper Case conversion
void convertIntoUpperCase(){
    char chlower[1000];
    cout << "Enter your name in lower case" << endl;
    cin >> chlower;
    int len = strlen(chlower);
    
    for(int i = 0; i < len; i++){
        char currentchar = chlower[i];

        if(chlower[i] >= 'a' && chlower[i] <= 'z'){           //if letter is a lowercase letter then only convert it
            chlower[i] = currentchar - 'a' + 'A';
        }
    }
    cout << "Coverted to upper case -->" << chlower << endl;
}

// Upper case to Lower Case conversion
void convertIntoLowerCase(){
    char chUpper[1000];
    cout << "Enter your name in lower case" << endl;
    cin >> chUpper;
    int len = strlen(chUpper);
    
    for(int i = 0; i < len; i++){
        char currentchar = chUpper[i];

        if(chUpper[i] >= 'A' && chUpper[i] <= 'Z'){           //if letter is a Upper case letter then only convert it
            chUpper[i] = currentchar - 'A' + 'a';
        }
    }
    cout << "Coverted to lower case -->" << chUpper << endl;
}

// Reverse char array
void reverseCharArray(){
    // 2 pointer approach
    char ch[100];
    cout << "Enter your name" << endl;
    cin.getline(ch, 100);
    int size = strlen(ch);

    int i = 0;
    int j = size - 1;

    while (i < j) {
        swap(ch[i], ch[j]);
        i++;
        j--;
    }
  cout << ch << endl;
}

void checkPalindrome() {
  char ch[100];
  cout << "Enter your name" << endl;
  cin.getline(ch, 100);
  int size = strlen(ch);

  int i = 0;
  int j = size - 1;

  while (i <= j) {
    if (ch[i] == ch[j]) {
      i++;
      j--;
    } else {
      cout << "Not Palindrome" << endl;
      return;
    }
  }

  cout << "It is a Palindrome" << endl;
}

// Char Functions

void charFunctions(){
    // String Concatenation
    char arr1[100];
    cout << "Enter input for arr1:" << endl;
    cin >> arr1;

    char arr2[100];
    cout << "Enter input for arr2:" << endl;
    cin >> arr2;

    cout << strcat(arr1,arr2) << endl;
}

int main(){
    // initchars();
    // ReplaceCharacter();
    // convertIntoUpperCase();
    // convertIntoLowerCase();
    // reverseCharArray();
    // checkPalindrome();
    charFunctions();
    return 0;
}