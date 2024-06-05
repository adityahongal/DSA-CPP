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



int main(){

    haskeyPairTwoSum();
    // return 0;
}