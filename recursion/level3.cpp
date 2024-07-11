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

// Leetcode 322 Coin Change
// You are given an integer array coins representing coins of different
// denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount.
// !!!!!!!

// If that amount of money cannot be made up by any combination of the coins,
// return -1. You may assume that you have an infinite number of each kind of
// coin.

// Example 1:
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

int solveCoinChange(vector< int > &coins, int amount) {

    if (amount == 0) {
        return 0;                   //0 amount create krne k liye kitne coins - base case
    }
    // initialize minimum coins
    //if amount < 0
    int minCoinAns = INT_MAX;

    //hr amount k liye poore coins k array ko
    //traverse krre h 
        for(int i=0; i<coins.size(); i++) {
            //coin value
            int coin = coins[i];

            //if coin value > amount value, no need to call recursive function
            //if coin value <= amount value , call recursive fiunction
            if( coin <= amount) {
                //1 coin toh use hogya, amount becomes amount-coins
                //baaki reciursion sambhal lega
                int recursionAns = solveCoinChange(coins, amount-coin);
                //ho skta h recursionAns valid ho ya fer Invalid 
                //invalid case -> recursionAns -> INT_MAX;
                //valid case -> recursionAns -> not equal to INT_MAX;
                if(recursionAns != INT_MAX) {
                    //valid answer aaaya h 
                    int coinsUsed = 1 + recursionAns;
                    //kya above answer minimum hai
                    minCoinAns = min(minCoinAns, coinsUsed);
                }
            }
        }

  return minCoinAns;
}
int coinchange(vector< int > &coins, int amount) {
    int ans = solveCoinChange(coins, amount);

    if (ans == INT_MAX) {
        return -1;
    }
    else{
        return ans;
    }
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
    // vector<int> robOne;
    // vector<int> robTwo;

    // robOne.push_back(1);
    // robOne.push_back(2);
    // robOne.push_back(3);
    // robOne.push_back(1);

    // robTwo.push_back(2);
    // robTwo.push_back(7);
    // robTwo.push_back(9);
    // robTwo.push_back(3);
    // robTwo.push_back(1);

    // cout << rob(robOne, robOne.size(), 0) << endl;
    // cout << rob(robTwo, robTwo.size(), 0) << endl;

    // Coin change
    vector< int > coinChangeCaseOne;
    int amountOne = 11;
    
    coinChangeCaseOne.push_back(1);
    coinChangeCaseOne.push_back(2);
    coinChangeCaseOne.push_back(5);

    vector< int > coinChangeCaseTwo;
    int amountTwo = 3;

    coinChangeCaseTwo.push_back(2);

    cout << coinchange(coinChangeCaseOne, amountOne) << endl;
    cout << coinchange(coinChangeCaseTwo, amountTwo) << endl;
    
    return 0;
}