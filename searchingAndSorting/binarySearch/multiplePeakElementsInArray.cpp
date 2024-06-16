// Leetcode Question 162

// 162. Find Peak Element

// Multiple Peaks in a Array
// Return any one peak

// A peak element is an element that is strictly greater than its neighbors.

// Given a 0-indexed integer array nums, find a peak element, and return its index. 
// If the array contains multiple peaks, return the index to any of the peaks.

// You may imagine that nums[-1] = nums[n] = -∞. 
// In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

// You must write an algorithm that runs in O(log n) time.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.
// Example 2:

// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2, 
// or index number 5 where the peak element is 6.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Check for edge cases: single element or first/last element being the peak
        if (nums.size() == 1) {
            return 0;
        } else if (nums[0] > nums[1]) {
            return 0;
        } else if (nums.back() > nums[nums.size() - 2]) {
            return nums.size() - 1;
        }

        // Binary search for peak element
        int start = 1;
        int end = nums.size() - 2; // Exclude last element as it was checked earlier

        while (start <= end) {
            int mid = start + (end - start) / 2; // Avoid overflow

            // Check for peak element condition and update search range
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] > nums[mid - 1]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // No peak element found
        return -1;
    }
};

int main() {
    vector<int> nums;

    // Use push_back to add elements (Example 1)
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    Solution solution;
    int peakIndex = solution.findPeakElement(nums);

    if (peakIndex == -1) {
        cout << "No peak element found." << endl;
    } else {
        cout << "Peak element index number is: " << peakIndex << endl;
    }

    return 0;
}
