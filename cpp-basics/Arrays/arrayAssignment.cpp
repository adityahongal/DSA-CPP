#include <climits>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

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

int main(){

    // haskeyPairTwoSum();
    // FindPivotIndexBruteForce();
    // findPivotIndex();
    // return 0;
}