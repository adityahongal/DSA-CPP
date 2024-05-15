#include<iostream>
using namespace std;

int getMultiplication( int a,int b, int c){
    int result = a*b*c;
    return result;
}

void printNameFiveTimes(){
    for ( int i = 1; i<=5; i++ ){
        cout << "ADDY" << endl;
    }
}

void printMultiples( int num){
    for ( int i = 1; i<=10; i++ ){
        cout << num*i << endl;
    }
}

int convertIntoCelcius( int far){
    int celcius = (far-32)*5/9;
    return celcius;
}

char convertToUpperCase ( char ch ){
    char answer = ch - 'a' + 'A';
    return answer;
}

int main(){


    // function call
    int multiplicationAnswer = getMultiplication(3,2,10);
    cout << multiplicationAnswer << endl;

    printNameFiveTimes();

    printMultiples(5);

    int convertedCelcius = convertIntoCelcius( 185 );
    cout << convertedCelcius << " degree celcius" << endl;

    char result = convertToUpperCase( 'k');
    cout << result << endl;

    return 0;
}