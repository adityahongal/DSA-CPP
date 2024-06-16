// Leetcode Question 1482

// 1482. Minimum Number of Days to Make m Bouquets

// You are given an integer array bloomDay, an integer m and an integer k.

// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] 
// and then can be used in exactly one bouquet.

// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. 
// If it is impossible to make m bouquets return -1.

// Example 1:

// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
// Output: 3
// Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
// We need 3 bouquets each should contain 1 flower.
// After day 1: [x, _, _, _, _]   // we can only make one bouquet.
// After day 2: [x, _, _, _, x]   // we can only make two bouquets.
// After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
// Example 2:

// Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
// Output: -1
// Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.
// Example 3:

// Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
// Output: 12
// Explanation: We need 2 bouquets each should have 3 flowers.
// Here is the garden after the 7 and 12 days:
// After day 7: [x, x, x, x, _, x, x]
// We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
// After day 12: [x, x, x, x, x, x, x]
// It is obvious that we can make two bouquets in different ways.

#include <iostream>
#include <vector>
#include <algorithm> // for std::min_element, std::max_element

using namespace std;

class Solution {
public:
    bool canMakeMBouquetsWithDDays(vector<int>& bloomDay, int m, int k, int D) {
        int counter = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            // Check if flower is bloomed on day D
            if (bloomDay[i] <= D) {
                counter++;
            } else {
                counter = 0; // Reset counter if flower isn't bloomed
            }

            // Make a bouquet if enough bloomed flowers are available
            if (counter >= k) {
                m--;
                counter = 0;
                if (m == 0) {
                    return true; // Made enough bouquets
                }
            }
        }
        return false; // Couldn't make enough bouquets
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        // Check if enough flowers exist for required bouquets
        long long int requirement = (long long int)m * (long long int)k;
        if (bloomDay.size() < requirement) {
            return -1;
        }

        // Find minimum and maximum bloom days
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = 0;
        while (start <= end) {
            int mid = start + (end - start) / 2; // Avoid overflow
            int day = mid;

            // Check if bouquets can be made with mid-day bloom
            if (canMakeMBouquetsWithDDays(bloomDay, m, k, day)) {
                ans = mid;
                end = mid - 1; // Look for earlier days if possible
            } else {
                start = mid + 1; // Look for later days if necessary
            }
        }
        return ans;
    }
};

int main() {
    vector<int> bloomDay; // Initialize empty vector

    // Use push_back to add bloom days (Example 1)
    bloomDay.push_back(1);
    bloomDay.push_back(10);
    bloomDay.push_back(3);
    bloomDay.push_back(10);
    bloomDay.push_back(2);

    int m = 3, k = 1;
    // int m = 3, k = 2;
    // int m = 2, k = 3;

    Solution solution;
    int minDaysToBloom = solution.minDays(bloomDay, m, k);

    if (minDaysToBloom == -1) {
        cout << "Cannot make " << m << " bouquets with " << k << " flowers each." << endl;
    } else {
        cout << "Minimum days to make " << m << " bouquets: " << minDaysToBloom << endl;
    }

    return 0;
}
