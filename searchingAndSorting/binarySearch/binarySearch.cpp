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

// same as above for vector arrays
int binarySearch(vector<int> &arr, int start, int end, int target) {
  int size = arr.size();
  int mid = (start + end) / 2;

  while (start <= end) {
    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] > target) {
      end = mid - 1;
    } else if (arr[mid] < target) {
      start = mid + 1;
    }

    mid = (start + end) / 2;
  }

  return -1;
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

int findPivotIndex(vector<int> &arr) {
  int size = arr.size();
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;

  while (start <= end) {
    
    if (start == end) {                          // In case there is only single element
      return start;
    }

    if (mid + 1 <= end && arr[mid] > arr[mid + 1]) {      // if we are standing on mid element/target itself
      return mid;                                         // example 16 > 2 then 16 is pivot
    }

    if (arr[start] > arr[mid]){
      end = mid - 1;                  // Move left and search
    } 
    else {
      start = mid + 1;                // Move right and search
    }

    // do not forget to update mid
    mid = start + (end - start) / 2;
  }

  // when nothing found
  return -1;
}

int search(vector<int> &nums, int target) {
  int pivotIndex = findPivotIndex(nums);
  int size = nums.size();
  int ans = -1;

  if (target >= nums[0] && target <= nums[pivotIndex]) {           // target is in range 0th index to pivot index
    ans = binarySearch(nums, 0, pivotIndex, target);
  } else {
    ans = binarySearch(nums, pivotIndex+1, size - 1, target);      // target is in range pivotIndex+1 to n-1(i.e. size-1)
  }

  return ans;
}

// Leetcode Ques no. 69
void findNearestSQRT() {
  int num = 51;
  int start = 0;
  int end = num;
  long long mid = start + (end - start) / 2;              // used this long long int to avoid integer overflow
  int ans = -1;

  while(start <= end){
    if (mid * mid == num) {
      cout << "SQRT is: " << mid << endl;
      return;
    }
    if (mid * mid < num){
      //answer may or may not be so
      //store and compute
      ans = mid;
      //go to right to find nearest answer
      start = mid+1;
    }
    else {
      ans = mid;
      //go to left to find nearest answer
      end = mid-1;
    }
    mid = start + (end - start) / 2;
  }
  cout << "SQRT is: " << ans << endl;
}

// Same as above with precision
int findSQRTWithPrecesion(int num) {

  int start = 0;
  int end = num;
  long long mid = start + (end - start) / 2;
  int ans = -1;

  while (start <= end) {
    if (mid * mid <= num) {
      ans = mid;
      start = mid + 1; // move left
    } else {
      end = mid - 1;
    }

    mid = start + (end - start) / 2;
  }

  return ans;
}

double precesionSQRT(int n) {
  double sqrt = findSQRTWithPrecesion(51);
  double step = 0.1;
  int precesion = 10;
  for (int i = 0; i < precesion; i++) {
    double j = sqrt;
    while (j * j <= n) {
      sqrt = j;
      j += step;
    }
    step /= 10;
  }
  return sqrt;
}

//Leetcode Ques no. 74
void findTargetIn2DSortedArray(vector<vector<int> > &arr, int target) {
  int rows = arr.size();
  int cols = arr[0].size();
  int size = rows * cols;               //To find Total Elements

  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;

  while (start <= end) {
    //mid ka use karkek 2D array ka rowIndex and colIndex find krenge
    int rowIndex = mid / cols;
    int colIndex = mid % cols;
    int currentNum = arr[rowIndex][colIndex];

    if (currentNum == target) {
      cout << "Target found at: row = " << rowIndex << " col = " << colIndex
           << endl;
      return;
    } else if (currentNum > target) {
      // move left
      end = mid - 1;
    } else {
      start = mid + 1;
    }

    mid = start + (end - start) / 2;
  }
}

// Given two integers one is a dividend and the other is the divisor, 
// we need to find the quotient when the dividend is divided by the divisor without the use of 
// any ” / “ and ” % “ operators

// Input: dividend = 10, divisor = 2
// Output: 5
// Explanation: 10/2 = 5.

// Input: dividend = 10, divisor = 3
// Output: 3
// Explanation: 10/3 = 3.33333… which is truncated to 3.

// Input: dividend = 10, divisor = -2
// Output: -5
// Explanation: 10/-2 = -5

int getQuotient(int dividend, int divisor) {
    //search space can be from -> (+ve dividend) to (-ve dividend)
    int s = 0;
    int e = dividend;
    int mid = s + ((e-s)>>1);               //right shift by 1 means divide by 2
    int ans = -1;

    while(s <= e) {
        //cout << "Printing mid: " << mid << endl;
        if((divisor * mid) == dividend) {
            return mid;
        }
        if((divisor*mid) < dividend) {
            //store and compute
            ans = mid;
            s = mid+1;
        }
        else {
            //left
            e = mid-1;
        }
        mid = s + ((e-s)>>1);
    }
    return ans;
}

// Given a sorted array arr[] of size N, some elements of array are moved to either of the 
// adjacent positions, i.e., arr[i] may be present at arr[i+1] or arr[i-1] 
// i.e. arr[i] can only be swapped with either arr[i+1] or arr[i-1]. 
// The task is to search for an element in this array.

// Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
// Output: 2
// Explanation: Output is index of 40 in given array i.e. 2

// Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 90
// Output: -1
// Explanation: -1 is returned to indicate the element is not present

// Search in nearly or almost sorted array

int searchInNearlySortedArray(int arr[], int size, int target)
{
    int s = 0;
    int e = size - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        // cout << "printing mid:  " << mid << endl;
        // cout << "target " << target << endl;
        // cout << "arr[mid]: " << arr[mid] << endl << endl;
        if (arr[mid] == target)
        {
            return mid; 
        }
        if (arr[mid - 1] == target)
        {
            return mid - 1;
        }
        if (arr[mid + 1] == target)
        {
            return mid + 1;
        }

        if (target > arr[mid])
        {
            // right
            s = mid + 2;
        }
        else
        {
            // left
            e = mid - 2;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

int findOddOccuringElement(int arr[], int size){
  int start = 0;
  int end = size - 1;
  int mid = start + (end - start) / 2;

  while (start <= end) {
    // single elem case
    if (start == end) {
      return start;
    }

    // if Duplicate element not exist
    if ( mid-1 >= 0 && arr[mid] != arr[mid-1] && mid+1 < size && arr[mid] != arr[mid+1] ){
      return mid;
    }

    // If duplicate element exist in left index
    if (mid-1 >= 0 && arr[mid] == arr[mid-1]) {
      int pairStartingIndex = mid -1;
      //check mid for even or odd
      if ( pairStartingIndex & 1 ){
        // pair starting index is odd
        // standing at right part
        // go to left
        end = mid - 1;
      }
      else {
        // pair starting index is even
        // standing at left part
        // go to right
        start = mid + 1;
      }
    }

    // If duplicate element exist in right index
    else if (mid+1 < size && arr[mid] == arr[mid+1]) {
        int pairStartingIndex = mid;
        //check mid for even or odd
        if ( pairStartingIndex & 1 ){               //These conditions same as above
          // pair starting index is odd
          // standing at right part
          // go to left
          end = mid - 1;
        }
        else {
          // pair starting index is even
          // standing at left part
          // go to right
          start = mid + 1;
        }
      }
    //update mid
    mid = start + (end - start) / 2;
  }
  cout << "Odd Occurance not found" << endl;
  return -1;
}

int main(){

    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8}; // for missing elem
    // int size = 9;                         // for missing elem

    // int crr[] = {0, 2, 1, 0};         // For Mountain Array
    // int size = 4;                     // For Mountain Array

    // int crr[] = {10, 20, 50, 40, 30};         // For Mountain Array
    // int size = 4;                             // For Mountain Array

    // // for pivot index
    // vector<int> v;

    // v.push_back(4);
    // v.push_back(5);
    // v.push_back(6);
    // v.push_back(7);
    // v.push_back(0);
    // v.push_back(1);
    // v.push_back(2);

    // // for 2d array find
    // vector<int> row1;
    // vector<int> row2;
    // vector<int> row3;

    // row1.push_back(1);
    // row1.push_back(2);
    // row1.push_back(3);
    // row1.push_back(4);

    // row2.push_back(5);
    // row2.push_back(6);
    // row2.push_back(7);
    // row2.push_back(8);

    // row3.push_back(9);
    // row3.push_back(10);
    // row3.push_back(11);
    // row3.push_back(12);

    // vector<vector<int> > arrB;
    // arrB.push_back(row1);
    // arrB.push_back(row2);
    // arrB.push_back(row3);

    // basicBinarySearch();
    // findFirstOccurance();
    // findLastOccurance();
    // findTotalOccurance();
    // findMissingElement(arr, size);
    // findPeakIndexInAMountainArray(crr, size);

    // // pivot index
    // int pivotIndex = findPivotIndex(v);
    // cout << "Pivot Index is: " << pivotIndex << endl;

    // // search in rotated and sorted array
    // int ans = search(v, 0);
    // cout << "Target is at: " << ans << "th Index" << endl;

    // // findNearestSQRT();
    // findSQRTWithPrecesion(51);
    // double sqrt = precesionSQRT(51);
    // cout << "Precesion SQRT is: " << sqrt << endl; // wont show all precesion so
    // // use printf 
    // printf("Most Precise sqrt is %0.10f", sqrt); cout << endl;

    // findTargetIn2DSortedArray(arrB, 7);

    // // Get Quotient
    // int dividend = 10;          // can be -10
    // int divisor = 2;            // can be -2

    // //mission is to find Quotient
    // int ans = getQuotient(abs(dividend), abs(divisor));
    // //ans answer positive values k hisaab se aara h 
    // if((dividend <0 && divisor>0) || (dividend >0 && divisor<0)) {
    //   ans = 0-ans;
    // }
    // cout << "Final Ans : " << ans << endl;

    // // for nearly sorted array check
    // int arrC[] = {10, 3, 40, 20, 50, 80, 70};
    // int sizeC = 7;
    // int targetC = 40;
    // int ans = searchInNearlySortedArray(arrC, sizeC, targetC);
    // cout << "Found at Index: " << ans << endl;

    // for odd occuring element
    int arrD[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 3, 3};
    int sizeD = 11;
    int ans = findOddOccuringElement(arrD, sizeD);
    cout << "Odd occuring Index is: " << ans << endl;
    cout << "Odd occuring Element is: " << arrD[ans] << endl;

    return 0;
}