#include <iostream>
#include <vector>
using namespace std;

void pointersInit() {

    int a = 5;
    cout << "Value of Variable: " << a << endl;             // when we want to access contents of a variable
    cout << "Address of Variable: " << &a << endl;          // when we want to access address of a variable

    // pointer create
    // To store address we need a pointer variable
    int *ptr = &a;
}

int main(){
    pointersInit();
    return 0;
}