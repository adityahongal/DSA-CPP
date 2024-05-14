#include<iostream>
using namespace std;

int main() {

    // && operator - Logical And operator

    // If all conditions are true then answer will be true
    // If any of the conditions are false then answer will be false

    // bool cond1 = true;
    // bool cond2 = false;
    // bool cond3 = true;

    // if (cond1 && cond2 && cond3) {
    //     cout << "All conditions are true" << endl;
    // }
    // else {
    //     cout << "All conditions are not true" << endl;
    // }

    
    // || operator - Logical Or operator

    // If any one condition is true then answer will be true
    // If all conditions are false then answer will be false

    bool cond1 = true;
    bool cond2 = false;
    bool cond3 = true;

    if (cond1 || cond2 || cond3) {
        cout << "Atleast one condition is true" << endl;
    }
    else {
        cout << "All conditions are not false" << endl;
    }


    //  ! operator - Logical Not operator

    // If condition is true then answer will be false and vice versa

    bool condition = false;
    cout << !condition << endl;

    return 0;
}