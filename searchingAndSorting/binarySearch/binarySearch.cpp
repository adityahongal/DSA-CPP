#include<iostream>
#include<vector>
using namespace std;

void basicBinarySearch(){
    int arr[] = {10,20,30,40,50,60,70,80,90,100};
    int size = 10;
    int start = 0;
    int end = size - 1;
    int mid = (start + end)/2;
    int target = 90;

    while( start <= end ){
        if( arr[mid] == target ){
            cout << "Element found at index " << mid << endl;
            return;
        }
        else if(target > arr[mid]){
            start = mid + 1;
            // check in right direction
        }
        else if( target < arr[mid] ){
            end = mid - 1;
            // check in left direction
        }
        // Update Mid
        mid = (start + end)/2;
    }
    cout << "Target not found" << endl;
}

int findFirstOccurance() {
  int arr[8] = {10, 20, 20, 30, 30, 30, 40, 50};
  int target = 30;
  int start = 0;
  int end = 7;
  // int mid = (start + end) / 2;
  int mid = start + (end - start) / 2; // Best Practice to avoid integer overflow (if sum of start and end is very big it will overflow)
  int answer = -1;

  while (start <= end) {
    if (arr[mid] == target) {
      answer = mid;
      // move towards left
      end = mid - 1;
    } else if (target > arr[mid]) {
      start = mid + 1;
    } else if (target < arr[mid]) {
      end = mid - 1;
    }
    //update mid
    mid = (start + end) / 2;
  }

  cout << "First Occurance of target " << target << " is at: " << answer
       << endl;
  return answer;
}

int findLastOccurance() {
  int brr[8] = {10, 20, 20, 30, 30, 30, 40, 50};
  int target = 30;
  int start = 0;
  int end = 7;
  // int mid = (start + end) / 2;
  int mid = start + (end - start) / 2; // Best Practice to avoid integer overflow (if sum of start and end is very big it will overflow)
  int answer = -1;

  while (start <= end) {
    if (brr[mid] == target) {
      answer = mid;
      // move towards right
      start = mid + 1;
    } else if (target > brr[mid]) {
      start = mid + 1;
    } else if (target < brr[mid]) {
      end = mid - 1;
    }
    //update mid
    mid = (start + end) / 2;
  }

  cout << "Last Occurance of target " << target << " is at: " << answer
       << endl;
  return answer;
}

int findTotalOccurance(){
    int firstOccurance = findFirstOccurance();
    int lastOccurance = findLastOccurance();
    int totalOccurance = lastOccurance - firstOccurance + 1;
    cout << "Total Occurance of target is: " << totalOccurance << endl;
    return totalOccurance;
    // Anwser will be 3 in case of target=30
    // Cz we have used the same array 2 times
}

void findMissingElement(int arr[], int size) {
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;
  int ans = -1;

  while (start <= end) {
    int difference = arr[mid] - mid;

    if (difference == 1) {
        // Go to right
      start = mid + 1;   
    } 
    else {
     //Store Answer
      ans = mid;

      // Go to left
      end = mid - 1;
    }

    mid = start + (end - start) / 2;
  }

  // try to exclude below statement and solve it in above logic HW
  if (ans + 1 == 0) {
    cout << "Missing Element is: " << size + 1 << endl;
    return;
  }

  cout << "Missing Element is: " << ans + 1 << endl;
  return;
}

// Leetcode 852
// find peak indes in a mountain array
// input [0,1,0]
// output 1
// solve in TC of O(logn)
void findPeakIndexInAMountainArray(int crr[], int size) {
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;

  while (start < end) {
    if (crr[mid] < crr[mid + 1]) {
      // in A section of graph
      // peak exists right side
      // so move right
      start = mid + 1;
    } else {
      // you might be in B section of graph
      // and you might be on peak element
      // move left without losing peak element so end = mid
      end = mid;
    }

    // update mid
    mid = start + (end - start) / 2;
  }

  cout << "Peak element is: " << start << endl;
}

int main(){

    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8}; // for missing elem
    // int size = 9;                         // for missing elem

    int crr[] = {0, 2, 1, 0};         // For Mountain Array
    int size = 4;                     // For Mountain Array

    // int crr[] = {10, 20, 50, 40, 30};         // For Mountain Array
    // int size = 4;                             // For Mountain Array

    // basicBinarySearch();
    // findFirstOccurance();
    // findLastOccurance();
    // findTotalOccurance();
    // findMissingElement(arr, size);
    findPeakIndexInAMountainArray(crr, size);
    return 0;
}