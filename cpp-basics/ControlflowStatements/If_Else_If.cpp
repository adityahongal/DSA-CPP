#include<iostream>
using namespace std;

int main(){

    int marks = 65;

    if(marks>90){
        cout << "Grade A" << endl;
    }
    else if(marks>80){
        cout << "Grade B" << endl;
    }
    else if(marks>70){
        cout << "Grade C" << endl;
    }
    else if(marks>60){
        cout << "Grade D" << endl;
    }
    
    return 0;
}