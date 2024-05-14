#include<iostream>
using namespace std;

int main(){

    int budget;
    cout << "enter your budget" << endl;

    //input
    cin >> budget;
    
    if(budget > 2000000) {
        cout << "You can buy this car" << endl;
    }
    else {
        cout << "You can't buy this car" << endl;
    }
    
    return 0;
}