#include <iostream>
using namespace std;

void probOne() {
    float f = 10.5;
    float p = 2.5;
    float *ptr = &f;
    (*ptr)++;
    *ptr = p;
    cout << *ptr << " " << f << " " << p << endl;
}

void probTwo() {
    int a = 7;
    int b = 17;
    int *c = &b;
    *c = 7;
    cout << a << " " << b << endl;
}

void probThree() {
    int *ptr = 0; // Null pointer
    int a = 10;
    // runtime error here because you cannot dereference a null pointer *ptr =
    // we cannot dereference a null pointer
    // fix -> ptr = &a
    *ptr = a;
    cout << *ptr << endl;
}

int main(){
    // probOne();
    // probTwo();
    probThree();
    return 0;
}