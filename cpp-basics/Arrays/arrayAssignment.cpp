#include <climits>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

void print2DVector(vector<vector<int> > arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      cout << arr[i][j] << "  ";
    }
    cout << endl;
  }
}

void printSet(set<int> mySet) {
  // Print the elements of the set (elements will be sorted)
  for (auto element : mySet) {                  //auto detects datatype automatically
    cout << element << " ";
  }
  cout << endl;
}

void printVector(vector<int> v) {
  cout << "Printing Vector" << endl;
  int size = v.size();
  for (int i = 0; i < size; i++) {
    // cout << v[i] << " "; // method 1
    cout << v.at(i) << " ";
  }
  cout << endl;
}

// Finding Key pair/Two Sum problem
// Time Complexity ---> O(nlogn)
// Space Complexity ---> O(1)
// We use Two Pointer Method

bool haskeyPairTwoSum(){
    // sum of 2 number in array should match with the target
    int target = 16;
    int krr[] = {1,4,45,6,10,8};
    int n = 6;

    sort(krr, krr+n);
    int low = 0;
    int high = n-1;

    while(low < high){
        int sum = krr[low] + krr[high];
        if(sum == target){
            cout << "At index: "<< low << " & "<< high << " Target Exists" << endl;
            return true;
        }
        else if(sum > target)
            high--;
        else
            low++;
    }
    return false;
}

void FindPivotIndexBruteForce() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(7);
  nums.push_back(3);
  nums.push_back(6);
  nums.push_back(5);
  nums.push_back(6);

  for (int i = 0; i < nums.size(); ++i) {
    int lsum = 0;
    int rsum = 0;

    // lsum
    for (int j = 0; j < i; j++)
      lsum += nums[j];

    // rsum
    for (int j = i + 1; j < nums.size(); ++j)
      rsum += nums[j];

    if (lsum == rsum)
      cout << "Pivot Index is " << i << endl;
  }
}

void findPivotIndex(){
    // vector creation
    vector<int> nums;

    // vector insertion
    // case 1 ans 3
    nums.push_back(1); // 0
    nums.push_back(7); // 1
    nums.push_back(3); // 2
    nums.push_back(6); // 3
    nums.push_back(5); // 4
    nums.push_back(6); // 5

    // case 2 ans -1
    // nums.push_back(1);
    // nums.push_back(2);
    // nums.push_back(3);

    // case 3 ans 0
    // nums.push_back(2);
    // nums.push_back(1);
    // nums.push_back(-1);

    //Initialize leftmost and rightmost index to 0
    vector<int> leftSum(nums.size(), 0);
    vector<int> rightSum(nums.size(), 0);

    // Calculate left Sum
    for (int i = 1; i < nums.size(); ++i) {
        leftSum[i] = leftSum[i - 1] + nums[i - 1];
        // cout << leftSum[i] << " " << leftSum[i - 1] << " " << nums[i - 1] << " "
        //      << i << endl; // debugging
    }
    cout << endl;
    // Calculate right Sum
    for (int i = nums.size() - 2; i >= 0; --i) {
        rightSum[i] = rightSum[i + 1] + nums[i + 1];
        // cout << rightSum[i] << " " << rightSum[i + 1] << " " << nums[i + 1] << "
        // "
        //      << i << endl; //
        // // debugging
    }

    // check
    for (int i = 0; i < nums.size(); ++i) {
        if (leftSum[i] == rightSum[i]) {
        cout << "Pivot Index is: " << i << endl;
        return;
        }
    }
    cout << "Pivot Index is: " << -1 << endl;
}

void missingNumberBySortMethod(){
    // sorting method complexity o(nlogn) + o(n) = o(nlogn) TC, o(1) SC
    vector<int> nums2;
    nums2.push_back(0);
    nums2.push_back(1);
    nums2.push_back(3);

    sort(nums2.begin(), nums2.end());
    for (int i = 0; i < nums2.size(); i++) {
        if (i == nums2[i]) {
        continue;
        } 
        else {
        cout << "The missing number using Sort Method is: " << i << endl;
        return;
        }
    }

    // if all index match with nums2[index] then size is the missing number or n
    cout << "The missing number using Sort Method is: " << nums2.size() << endl;
}

void missingNumberByXORMethod(){
    // XOR method complexity o(n) TC, o(1) SC
    vector<int> nums3;
    nums3.push_back(9);
    nums3.push_back(6);
    nums3.push_back(4);
    nums3.push_back(2);
    nums3.push_back(3);
    nums3.push_back(5);
    nums3.push_back(7);
    nums3.push_back(0);
    nums3.push_back(1);

    int ans=0;
    // Array XOR
    for (int i=0; i<nums3.size(); i++){
        ans = ans ^ nums3[i];
    }
    // index XOR
    int n=nums3.size();
    for( int i=0;i<=n;i++){
        ans = ans ^ i;
    }
    cout << "The missing number using XOR Method is: " << ans << endl;
}

// Leetcode 26
// Given an integer array nums sorted in non-decreasing order, remove the
// duplicates in-place such that each unique element appears only once. The
// relative order of the elements should be kept the same. Then return the
// number of unique elements in nums. Consider the number of unique elements of
// nums to be k, to get accepted, you need to do the following things: • Change
// the array nums such that the first k elements of nums contain the unique
// elements in the order they were present in nums initially. The remaining
// elements of nums are not important as well as the size of nums:. • Return k.
// Remove Duplicates
// Input: nums = [0,0,1, 1, 1,2,2,3,3,4]
// Output: 5, nums =
// ［0,1,2,3,4._,_,_,_,_］
// Explanation: Your function should return k = 5, with the
// first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are
// underscores).

void removeDuplicates() {
  vector<int> arr;
  arr.push_back(0);
  arr.push_back(0);
  arr.push_back(1);
  arr.push_back(1);
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(3);
  arr.push_back(4);

  int i = 1, j = 0;

  while (i < arr.size()) {
    if (arr[i] == arr[j]) {
      i++;
    } else
      arr[++j] = arr[i++];
    // else {
    //   j++;
    //   arr[j] = arr[i];
    //   i++;
    // }
  }
  cout << "K is: " << j + 1 << endl;
  printVector(arr);
}

// Finding Max Average of Sub Array
// By Brute Force
// More time Complexity

void maxAverageSubArrayBruteForce() {
    vector<int> nums;
    int k = 4;

    nums.push_back(1);
    nums.push_back(12);
    nums.push_back(-5);
    nums.push_back(-6);
    nums.push_back(50);
    nums.push_back(3);

    int size = nums.size();

    int maxSum = INT_MIN;
    int i = 0, j = k - 1;

    while (j <= size) {
      int sum = 0;
      for (int y = i; y <= j; y++) {
        sum += nums[y];
      }

      maxSum = max(maxSum, sum);
      i++;
      j++;
    }

    double Avg = maxSum / (double)k;
    cout << "Max Avg by brute force is: " << Avg << endl;
    ;
}

// Finding Max Average of Sub Array
// By Sliding window method
// O(n) time Complexity

void maxAverageSubArraySlidingWindowMethod() {
    vector<int> nums;
    int k = 4;

    nums.push_back(1);
    nums.push_back(12);
    nums.push_back(-5);
    nums.push_back(-6);
    nums.push_back(50);
    nums.push_back(3);

    int size = nums.size();
    int i = 0, j = k - 1;
    int sum = 0;
    for (int y = i; y <= j; ++y) {
      sum += nums[y];
    }

    int maxSum = sum;
    j++;
    while (j < size) {
      sum = sum - nums[i++];
      sum = sum + nums[j++];
      maxSum = max(maxSum, sum);
    }

    double Avg = maxSum / (double)k;
    cout << "Max Avg by Sliding Window method is: " << Avg << endl;
    ;
}

// leetcode 75 sort colors
void sortColors(){
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(0);
    printVector(arr);

    int size = arr.size();
    int left = 0;
    int right = size - 1;
    int mid = 0;

    while (mid <= right) {
      if (arr[mid] == 0) {
        swap(arr[mid], arr[left]);
        left++;
        mid++;
      } else if (arr[mid] == 2) {
        swap(arr[mid], arr[right]);
        right--;
      } else {
        mid++;
      }
    }

    printVector(arr);
}

// Move all negative number to left side of the array in place
// no order required
void sortNegNumbersToLeft() {
  // aproach 1 Using STL TC- Onlogn SC- O(n) n-> size of ar
  // aproach 2 Dutch National flag method or 2 pointer

  vector<int> arr;
  arr.push_back(-9);
  arr.push_back(6);
  arr.push_back(4);
  arr.push_back(2);
  arr.push_back(-3);
  arr.push_back(5);
  arr.push_back(-7);
  arr.push_back(0);
  arr.push_back(-1);

  // low - manages neg numbers
  // high - manages pos numbers

  int left = 0;
  int right = arr.size() - 1;

  while (left < right) {
    if (arr[left] < 0) {
      left++;
    } else if (arr[right] > 0) {
      right--;
    } else {
      swap(arr[left], arr[right]);
    }
  }

  printVector(arr);

  // TC - O(n)
  // SC - O(1)
}

// Find Duplicate number mid level leetcode ques no. 287 
// only 1 integer will be repeating many
// times arr will be of size n and belong to [1,N]
// Dont modify arrays

void findDuplicateNumberInPlace() {
  vector<int> arr;
  arr.push_back(1);
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(2);
  arr.push_back(2);

  vector<int> nums;
  nums.push_back(5);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(4);
  nums.push_back(2);

  vector<int> num;
  num.push_back(3);
  num.push_back(3);
  num.push_back(3);
  num.push_back(3);
  num.push_back(3);

  // aproach 1 would be to sort and compare i = i+1 then return duplicate number
  // i visit the loop only til N-1 not N because i+1 will be out of bound
  sort(arr.begin(), arr.end());
  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      cout << "The Duplicate Number is: " << arr[i] << endl;
      break;
    }
  }

  // aproach 2  Negative marking method
  int ans = -1;

  for (int i = 0; i < nums.size(); i++) {

    int index = abs(nums[i]);

    // already visited check
    if (nums[index] < 0) {
      ans = index;
      break;
    }

    // mark visited
    nums[index] *= -1;
  }

  cout << "The duplicate number is: " << ans << endl;

  // approach 3 positioning method
  while (num[0] != num[num[0]]) {
    swap(num[0], num[num[0]]);
  }

  cout << "The duplicate number is: " << num[0] << endl;

  // approach 4 solve with binary search without modifying array
}

// Find missing elements with Duplicates
// We used Missing method/Negative Marking method
// Can use Sort and Swap method too

void findMissingElementWithDuplicates() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(5);
  nums.push_back(3);
  nums.push_back(4);

  // by visiting method
  for (int i = 0; i < nums.size(); i++) {
    int index = abs(nums[i]);
    if (nums[index - 1] > 0) {
      nums[index - 1] *= -1;
    }
  }

  printVector(nums);

  cout << "The missing numbers are ";
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > 0)
      cout << i + 1 << " ";
  }

  cout << endl;
}

// first repeating element GFG
// Given an array arrl] of size n, find the first repeating element. The element
// should occur more than once and the index of its first occurrence should be
// the smallest. Note:- The position you return should be according to 1-based
// indexing. Example 1: Input: n = 7 arr] = {1, 5, 3, 4, 3, 5, 6} Output: 2
// Explanation:
// 5 is appearing twice and its first appearence is at index 2 which is less
// than 3 whose first occuring index is 3.

void findFirstRepeatingElement() {
  vector<int> nums;
  nums.push_back(1);
  nums.push_back(5);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(3);
  nums.push_back(5);
  nums.push_back(6);

  // // brute force approach compare each element and return first occurance
  // for (int i = 0; i < nums.size(); i++) {

  //   for (int j = i + 1; j < nums.size(); j++) {
  //     if (nums[i] == nums[j]) {

  //       cout << "Repeated Number Index is: " << i + 1 << endl;
  //       return;
  //     }
  //   }
  // }
  // // TC is O(n) + O(n-1) = O(n^2) SC - O(1)
  // cout << "Repeated Number Index is: " << -1 << endl;

  // optimised soln
  // storing the occurance of numbers in hash unordered map
  // Hashing
  unordered_map<int, int> hash;
  for (int i = 0; i < nums.size(); i++) {
    hash[nums[i]]++;
  }

  for (int i = 0; i < nums.size(); i++) {
    if (hash[nums[i]] > 1) {
      cout << "Repeated Number index is: " << i + 1 << endl;
      return;
    }
  }
  // TC is O(n) sc is O(1)
  cout << "Repeated Number Index is: " << -1 << endl;
}

// Given three arrays sorted in increasing order. Find the elements that are
// common in all three arrays. Note: can you take care of the duplicates without
// using any additional Data Structure? Example 1: Input: n1 = 6; A = （1,5, 10,
// 20, 40, 80｝ n2 = 5; B = {6, 7, 20, 80, 100} n3 = 8; C = {3, 4, 15, 20, 30,
// 70, 80, 120} Output: 20 80 Explanation: 20 and 80 are the only common
// elements in A, B and C.

// Expected Time Complexity: 0(n1 + n2 + n3)
// Expected Auxiliary Space: 0(n1 + n2 + n3)
// Constraints:
// 1 <= n1, n2, n3 <= 10^5
// The array elements can be both positive or negative integers.

void findCommonElementsIn3SortedArray() {
  int n1 = 6;
  int a[6] = {1, 5, 10, 20, 40, 80};
  int n2 = 5;
  int b[5] = {6, 7, 20, 80, 100};
  int n3 = 8;
  int c[8] = {3, 4, 15, 20, 30, 70, 80, 120};

  set<int> ans;                                //Used STL Set to avoid duplicate elements
  int i, j, k;
  i = j = k = 0;

  while (i < n1 && j < n2 && k < n3) {
    if (a[i] == b[j] && b[j] == c[k]) {
      ans.insert(a[i]);
      i++;
      j++;
      k++;
    } else if (a[i] < b[j]) {
      i++;
    } else if (b[j] < c[k]) {
      j++;
    } else {
      k++;
    }
  }

  cout << "Common element are: ";
  printSet(ans);
}

// Wave print a matrix
// use the below command to run in C++ 11 version compatible mode
// g++ -std=c++11 arrayAssignment.cpp -o temp_executable && ./temp_executable && rm temp_executable

void WavePrintMatrix() {
  // vector<vector<int> > v = {{1, 2, 3, 4},
  //                          {5, 6, 7, 8},
  //                          {9, 10, 11, 12}};

  int r1[] = {1, 2, 3, 4};
  int r2[] = {5, 6, 7, 8};
  int r3[] = {9, 10, 11, 12};
  int r4[] = {13, 14, 15, 16};
  int r5[] = {17, 18, 19, 20};

  vector<int> row1(r1, r1 + sizeof(r1) / sizeof(r1[0]));
  vector<int> row2(r2, r2 + sizeof(r2) / sizeof(r2[0]));
  vector<int> row3(r3, r3 + sizeof(r3) / sizeof(r3[0]));
  vector<int> row4(r4, r4 + sizeof(r4) / sizeof(r4[0]));
  vector<int> row5(r5, r5 + sizeof(r5) / sizeof(r5[0]));

  vector<vector<int> > v;
  v.push_back(row1);
  v.push_back(row2);
  v.push_back(row3);
  v.push_back(row4);
  v.push_back(row5);

  int row = v.size();
  int col = v[0].size();

  for( int startCol = 0; startCol < col; startCol++){
    //Even no. of colums --> Top to bot --> Using Bitwise AND
    if((startCol & 1) == 0){
      for( int i = 0; i < row; i++){
        cout << v[i][startCol] << " ";
      }
    }
    else{
      //Odd no. of columns
      for( int i = row - 1; i>=0 ; i--){
        cout << v[i][startCol] << " ";
      }
    }
  }
}

// spiralprint matrix leet code 54
void SpiralPrintMatrix() {
  int r1[] = {1, 2, 3, 4, 5, 6};
  int r2[] = {7, 8, 9, 10, 11, 12};
  int r3[] = {13, 14, 15, 16, 17, 18};
  int r4[] = {19, 20, 21, 22, 23, 24};
  int r5[] = {25, 26, 27, 28, 29, 30};

  vector<int> row1(r1, r1 + sizeof(r1) / sizeof(r1[0]));
  vector<int> row2(r2, r2 + sizeof(r2) / sizeof(r2[0]));
  vector<int> row3(r3, r3 + sizeof(r3) / sizeof(r3[0]));
  vector<int> row4(r4, r4 + sizeof(r4) / sizeof(r4[0]));
  vector<int> row5(r5, r5 + sizeof(r5) / sizeof(r5[0]));

  vector<vector<int> > v;

  v.push_back(row1);
  v.push_back(row2);
  v.push_back(row3);
  v.push_back(row4);
  v.push_back(row5);
  print2DVector(v);

  vector<int> ans;

  int rows = v.size();
  int cols = v[0].size();
  int totalElements = rows * cols;

  int startingRow = 0;
  int endingCol = cols - 1;
  int endingRow = rows - 1;
  int startingCol = 0;

  int count = 0;

  while (count < totalElements) {
    // print starting row
    for (int i = startingCol; i <= endingCol && count < totalElements; i++) {
      ans.push_back(v[startingRow][i]);
      count++;
      // if(count >= totalElements) {                  //we added this in for loop itself
      //   break;
      // }
    }
    startingRow++;

    // print ending col
    for (int i = startingRow; i <= endingRow && count < totalElements; i++) {
      ans.push_back(v[i][endingCol]);
      count++;
    }
    endingCol--;

    // print ending row
    for (int i = endingCol; i >= startingCol && count < totalElements; i--) {
      ans.push_back(v[endingRow][i]);
      count++;
    }
    endingRow--;

    // print starting col
    for (int i = endingRow; i >= startingRow && count < totalElements; i--) {
      ans.push_back(v[i][startingCol]);
      count++;
    }
    startingCol++;
  }

  printVector(ans);
}

void AddTwoNumbersByTwoArrays() {
  int a[] = {0, 9, 5, 4, 9};
  int b[] = {2, 1, 4};

  string ans;
  int i = 4;
  int j = 2;
  int carry = 0;
  // adding both the arrays till the both the index are same
  while (i >= 0 && j >= 0) {
    int x = a[i] + b[j] + carry;
    int digit = x % 10;
    carry = x / 10;
    ans.push_back(digit + '0');
    i--;
    j--;
  }

  // if some left most digits are left to add in array a
  while (i >= 0) {
    int x = a[i] + carry;
    int digit = x % 10;
    carry = x / 10;
    ans.push_back(digit + '0');
    i--;
  }

  // if some left most digits are left to add in array b
  while (j >= 0) {
    int x = b[j] + carry;
    int digit = x % 10;
    carry = x / 10;
    ans.push_back(digit + '0');
    j--;
  }

  if (carry) {
    ans.push_back(carry + '0');
  }

  // to remove extra zeros in the starting
  while (ans[ans.size() - 1] == '0') {
    ans.pop_back();
  }
  // the answer should be reversed to
  reverse(ans.begin(), ans.end());

  cout << "Sum of two numbers is: " << ans << endl;
}

int main(){

    // haskeyPairTwoSum();
    // FindPivotIndexBruteForce();
    // findPivotIndex();
    // missingNumberBySortMethod();
    // missingNumberByXORMethod();
    // removeDuplicates();
    // maxAverageSubArrayBruteForce();
    // maxAverageSubArraySlidingWindowMethod();
    // sortColors();
    // sortNegNumbersToLeft();
    // findDuplicateNumberInPlace();
    // findMissingElementWithDuplicates();
    // findFirstRepeatingElement();
    // findCommonElementsIn3SortedArray();
    // WavePrintMatrix();
    // SpiralPrintMatrix();
    AddTwoNumbersByTwoArrays();
    // return 0;
}