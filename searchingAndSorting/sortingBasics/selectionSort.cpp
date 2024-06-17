#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v) {
  cout << "Printing Vector" << endl;
  int size = v.size();
  for (int i = 0; i < size; i++) {
    // cout << v[i] << " "; // method 1
    cout << v.at(i) << " ";
  }
  cout << endl;
}

void selectionSortASC(vector<int> &v) {

  int size = v.size();

  for(int i=0;i<size -1 ; i++){
    int minIndex = i; // initialize first elem of array comparison as smallest then check for each element or you can use max infinity
    
    // find min index 
    for(int j=i+1; j<size; j++) {
      if(v[j] < v[minIndex]) {
        minIndex = j;
      }
    }

    // after find min index swap
    swap(v[i], v[minIndex]);
  }
}

void selectionSortDSC(vector<int> &v) {

  int size = v.size();

  for(int i=0;i<size -1 ; i++){
    int minIndex = i; // initialize first elem of array comparison as smallest then check for each element or you can use max infinity
    
    // find min index 
    for(int j=i+1; j<size; j++) {
      if(v[j] > v[minIndex]) {
        minIndex = j;
      }
    }

    // after find min index swap
    swap(v[i], v[minIndex]);
  }
}

int main() {

  vector<int> v;

  v.push_back(44);
  v.push_back(33);
  v.push_back(55);
  v.push_back(22);
  v.push_back(11);
  
  printVector(v);

  selectionSortASC(v);
  printVector(v);

  selectionSortDSC(v);
  printVector(v);

  return 0;
}