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

void insertionSort(vector<int> &v) {
  int size = v.size();
  for (int i = 1; i < size; i++) {
    int key = v[i];
    int j = i - 1;

    // shift elements from 0 to i-1 
    while(j>= 0 && v[j] > key) {
      v[j+1] = v[j];
      j--;
    }
    v[j+1] = key;                         // Insertion. Insertion happens cz Here j becomes -1 after while loop completes
  }
}

int main() {

  vector<int> v;

  v.push_back(5);
  v.push_back(4);
  v.push_back(3);
  v.push_back(2);
  v.push_back(1);

//   v.push_back(44);
//   v.push_back(33);
//   v.push_back(55);
//   v.push_back(22);
//   v.push_back(11);

  printVector(v);

  insertionSort(v);
  printVector(v);

  return 0;
}