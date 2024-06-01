#include <iostream>
#include <vector> // needs header
using namespace std;

// void printArray(int a[], int size) {
//   for (int i = 0; i < size; i++) {
//     cout << a[i] << endl;
//   }
// }

// void basicArrayOps() {
//   // static memory allocation of an array
//   int arr[5] = {1, 2, 4, 5, 7};
//   printArray(arr, 5);

//   // dynamic memory allocation but not shrink

//   int size;
//   cout << "enter size of dynamic array" << endl;
//   cin >> size;
//   int *brr = new int[size];
//   // the value stored will be either 0 or garbage if
//   // not entered any
//   // can not add more elements then specified size taken from user

//   // To add user input to the array
//   cout << "Enter your input" << endl;
//   for (int i = 0; i < size; i++) {
//     int data;
//     cin >> data;
//     brr[i] = data;
//   }
//   printArray(brr, size);
// }

void printVectors(vector<int> v){
    // to know size of vectors
    int size = v.size();

    // Print the vectors
    for (int i = 0; i < size; i++){
        cout << v[i] << endl;
    }
}

void vectors(){
    // initialize a vector
    vector<int> v;

    // Insert elements into vector
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);

    // To check Capacity and size of vector
    while(1){
    int data;
    cout << "Enter data: " << endl;
    cin >> data;
    v.push_back(data);
    cout << "Capacity: " << v.capacity() << " Size: " << v.size() << endl; 
    }

    printVectors(v);
    
}

int main(){

    // basicArrayOps();
    vectors();
    return 0;
}