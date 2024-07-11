#include <climits>
#include <iostream>
#include <vector>
using namespace std;

// Check if array is sorted or not using recursion
bool checkSorted(int arr[], int size, int index){
    // Base case: if index reaches the end of array, return true
    if(index == size - 1)
        return true;
    
    bool currAns = false;
    bool recursionKaAns = false;
    //1 case solve
    if(arr[index+1] > arr[index]) 
    {
        currAns = true;
    }
    //Recursive call
    recursionKaAns = checkSorted(arr,size,index+1);

    return (currAns && recursionKaAns);                  // checks and return true if both cases are true

}

// Include Exclude Pattern ! ! ! ! ! ! ! !
void printSubsequences(string str, int i, string output,vector<string> &ans) {
    //base case
    if(i == str.length()) {
        // cout << output << endl;
        ans.push_back(output);
        return;
    }

    char ch = str[i];
    //include ch 
    printSubsequences(str,i+1,output + ch,ans);
    //exclude ch
    printSubsequences(str,i+1,output,ans);
}

// Leetcode 198. House Robber
int rob(vector<int> &nums, int size, int index) {
    if(index >= size) {
        return 0;
    }

    // rob -> ith index don't rob -> i+1 th index
    // Include ith index
    int includeAns = nums[index] + rob(nums, size, index + 2);

    // Exclude ith index
    // do not rob -> ith index  rob -> i+1 index
    int excludeAns = 0 + rob(nums, size, index + 1);

    int finalAns = max(includeAns, excludeAns);
    return finalAns;
}

int main(){

    // int arr[] = {10,20,30,40,50};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // int index = 0;
    // bool ans = checkSorted(arr,size, index);
    // cout << "Array is sorted or not: " << ans << endl;

    // Include Exclude Pattern ! ! ! ! ! ! ! !
    // string str = "abc";
    // string output = "";
    // int index=0;

    // vector<string> ans;
    // printSubsequences(str,index,output,ans);
    // for(auto index: ans) {
    // cout << index << endl;
    // }

    // House Rob
    vector<int> robOne;
    vector<int> robTwo;

    robOne.push_back(1);
    robOne.push_back(2);
    robOne.push_back(3);
    robOne.push_back(1);

    robTwo.push_back(2);
    robTwo.push_back(7);
    robTwo.push_back(9);
    robTwo.push_back(3);
    robTwo.push_back(1);

    cout << rob(robOne, robOne.size(), 0) << endl;
    cout << rob(robTwo, robTwo.size(), 0) << endl;
    
    return 0;
}