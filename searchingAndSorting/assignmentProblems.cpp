#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
using namespace std;

// Leetcode 532 K diff pairs

// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

// A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

// 1. 0 <= i, j < nums.length
// 2. i != j
// 3. |nums[i] - nums[j]| == k
// Notice that |val| denotes the absolute value of val.

// Example 1:

// Input: nums = [3,1,4,1,5], k = 2
// Output: 2
// Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
// Although we have two 1s in the input, we should only return the number of unique pairs.

// Example 2:

// Input: nums = [1,2,3,4,5], k = 1
// Output: 4
// Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).

// Leetcode 532 K diff pairs - Using Two Pointer Approach - T.C. O(n^2)

void kDiffPairsUsingTwoPointer() {
  vector< int > nums;
  int k = 2;
  nums.push_back(3);
  nums.push_back(1);
  nums.push_back(4);
  nums.push_back(1);
  nums.push_back(5);

  // int k = 0;
  // nums.push_back(3);
  // nums.push_back(3);
  // nums.push_back(3);
  // nums.push_back(3);
  // nums.push_back(3);
  // nums.push_back(3);

//   int k = 1;
//   nums.push_back(1);
//   nums.push_back(2);
//   nums.push_back(3);
//   nums.push_back(4);
//   nums.push_back(5);

  // sort the vector
  sort(nums.begin(), nums.end());

  int i = 0;
  int j = 1;
  int size = nums.size();
  set< pair< int, int > > answer;               // We use SET to store distinct pairs

  while (j < size) {
    int difference = nums[j] - nums[i];

    if (difference == k) {
      answer.insert(make_pair(nums[i], nums[j]));
      i++;
      j++;
    } 
    else if (difference > k) {
      i++;
    } 
    else
      j++;

    if (i == j)
      j++;
  }

  cout << "Unique K-Diff pair count by two pointer method is: " << answer.size()
       << endl;
}

// using binary search
int binarySearch(vector< int > &nums, int start, int target) {

  int end = nums.size() - 1;
  int mid = start + (end - start) / 2;

  while (start <= end) {
    if (nums[mid] == target) {
      return mid;
    } else if (target > nums[mid]) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }

  return -1;
}

void kDiffPairsUsingBinarySearch() {
  vector< int > nums;
  int k = 2;
  nums.push_back(3);
  nums.push_back(1);
  nums.push_back(4);
  nums.push_back(1);
  nums.push_back(5);

  sort(nums.begin(), nums.end());

  set< pair< int, int > > answer;

  for (int i = 0; i < nums.size(); i++) {
    if (binarySearch(nums, i + 1, nums[i]+k) != -1) {
      answer.insert(make_pair(nums[i], nums[i] + k));
    }
  }

  cout << "K-Diff Pairs count using binary search is: " << answer.size()
       << endl;
}

int main (){
    // kDiffPairsUsingTwoPointer();
    kDiffPairsUsingBinarySearch();
    return 0;
}