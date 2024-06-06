#include <climits>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <set>
#include <unordered_map>
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

int main(){

    // haskeyPairTwoSum();
    // FindPivotIndexBruteForce();
    // findPivotIndex();
    // missingNumberBySortMethod();
    // missingNumberByXORMethod();
    removeDuplicates();
    // return 0;
}