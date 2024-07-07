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

int main(){
    probOne();
    return 0;
}