// Leetcode Question No. 875

// There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. 
// Each hour, she chooses some pile of bananas and eats k bananas from that pile. 
// If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

// Example 1:
// Input: piles = [3,6,7,11], h = 8
// Output: 4

// Example 2:
// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

// Example 3:
// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

#include <iostream>
#include <vector>
#include <algorithm> // for std::max_element

using namespace std;

class Solution {
public:
    bool canKokoFinishBananasWithKSpeed(vector<int>& piles, int h, int k) {
        long long int totalHoursTaken = 0;
        for (int i = 0; i < piles.size(); i++) {
            // Integer division with rounding up (ceiling)
            totalHoursTaken += (piles[i] + k - 1) / k;
        }
        return totalHoursTaken <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int ans = 0;

        // TC: O(Log(Max(Piles)) * O(n)) -> O(n * log(max(piles)))
        while (start <= end) {
            int mid = start + (end - start) / 2; // Avoid overflow
            int k = mid;
            if (canKokoFinishBananasWithKSpeed(piles, h, k)) {
                // Koko can finish with this speed (or faster)
                ans = k;
                end = mid - 1;
            } else {
                // Koko needs to eat faster
                start = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> piles;
    piles.push_back(3);
    piles.push_back(6);
    piles.push_back(7);
    piles.push_back(11);

    int h = 8;

    Solution solution;
    int minSpeed = solution.minEatingSpeed(piles, h);

    cout << "Minimum eating speed: " << minSpeed << endl;

    return 0;
}
