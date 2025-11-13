#include <vector>
#include <algorithm>
#include <cstdlib> // for abs
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // Step 1: Sort the array
        int closestSum = nums[0] + nums[1] + nums[2]; // Initialize with the first 3 elements' sum

        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                // Update closestSum if currentSum is closer to target
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                // Move pointers
                if (currentSum < target) {
                    ++left;  // Need a bigger sum
                } else if (currentSum > target) {
                    --right; // Need a smaller sum
                } else {
                    return currentSum; // Perfect match
                }
            }
        }

        return closestSum;
    }
};
