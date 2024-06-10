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

int main(){

    // basicBinarySearch();
    // findFirstOccurance();
    // findLastOccurance();
    findTotalOccurance();
    return 0;
}