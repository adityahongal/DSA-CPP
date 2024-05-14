#include<iostream>
using namespace std;

int main(){

    int height;
    cout << "Enter height in feet :" << endl;
    cin >> height;

    int weight;
    cout << "Enter weight in kgs :" << endl;
    cin >> weight;

    if(height > 5){

        if(weight > 70){
            cout << "You have good BMI" << endl;
        }
        else {
            cout << "You have bad BMI" << endl;
        }
    }
    else {
        cout << "Do Workout" << endl;
    }
    
    return 0;
}