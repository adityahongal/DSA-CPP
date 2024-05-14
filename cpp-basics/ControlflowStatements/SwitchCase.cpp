#include<iostream>
using namespace std;

int main(){

    char grade;
    cout << "Enter your grade:" << endl;
    cin >> grade;

    switch(grade){

        case 'A': cout << "your marks are in range 90 to 100" << endl; 
        break;
        case 'B': cout << "your marks are in range 80 to 90" << endl; 
        break;
        case 'C': cout << "your marks are in range 70 to 80" << endl; 
        break;
        case 'D': cout << "your marks are in range 60 to 70" << endl;
        break;
        default: cout << "your marks are in range 0 to 60" << endl;
    }    

    return 0;
}







// CONDITIONS PERTAINING to "Switch" case 

// 1. Expressing type in case
// you can keep the conditions as int/char/enum
// but cannot as float/string

// 2. Keep unique case values
// for example id there's case A,case B,etc and then again you declare case B, then it wont work.

// 3. No range checking
// for example case 1: age>18 statement dont work
// case should be constant

// 4. Fall through behaviour
// If there is no break statements between the cases then it will continue to execute all the statements

// 5. Execution order
// It should be in sequential order