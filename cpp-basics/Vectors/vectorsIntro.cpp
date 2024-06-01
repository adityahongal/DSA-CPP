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
    cout << "Printing Vector:" << endl;
    for (int i = 0; i < size; i++){
        // cout << v[i] << " ";            //method 1 to print
        cout << v.at(i) << " ";
    }
    cout<< endl;
}

// Native method of vector to print
void printVectorNativeMethod(vector<char> v) {
    cout << "Native method of print:" << endl;
  // for each loop
  for (auto it : v) {                               // Auto selects keyword automatically                              
    cout << it << " ";
  }
  cout << endl;
}

void vectors(){
    // initialize a vector
    vector<int> v;

    // Insert elements into vector
    // v.push_back(10);
    // v.push_back(20);
    // v.push_back(30);

    // To check Capacity and size of vector
    // while(1){
    // int data;
    // cout << "Enter data: " << endl;
    // cin >> data;
    // v.push_back(data);
    // cout << "Capacity: " << v.capacity() << " Size: " << v.size() << endl; 
    // }

    // To delete a element we call it pop in vector and it pops from the END of the array
    // 10,20,30 ---> 30 will be popped
    // v.pop_back();

    // Dynamic Vector Demo
    // int n;
    // cout << "Enter size of dynamic array" << endl;
    // cin >> n;
    // for (int i = 0; i < n; i++){
    //     int data;
    //     cin >> data;
    //     v.push_back(data);
    // }
    // printVectors(v);
    // for(int i=0; i < 10; i++){
    //     v.push_back(99);
    // }

    // To clear the vector
    // v.clear();

    // printVectors(v);

    // Vector initialization
    // vector<int>arr;           // default with no data and 0 size;
    // vector<int>arr2(5,-1);       // with n size and specific elements
    // vector<int> arr3 = {1, 2, 3, 4, 5};
    // vector<int> arr4{10,20,30,40,50};
    // printVectors(arr2);

    // Copying into vector
    // vector<int> arr5 = {1,2,3};
    // vector<int> arr6(arr5);
    // printVectors(arr6);

    // available with all datatypes
    vector<char> chars;

    chars.push_back('a');
    chars.push_back('b');
    chars.push_back('c');

    // cout << "Front element: " << chars[0] << endl;
    // cout << "Back element: " << chars[chars.size()-1] << endl;   //Manual method of printing

    // Printing using vector inbuilt methods
    cout << "Front element: " << chars.front() << endl
       << "Back element: " << chars.back() << endl;

    printVectorNativeMethod(chars);
    
}

int main(){

    // basicArrayOps();
    vectors();
    return 0;
}