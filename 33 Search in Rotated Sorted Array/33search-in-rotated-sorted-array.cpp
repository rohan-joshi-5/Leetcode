#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Target found
            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is the strictly sorted one
            if (nums[left] <= nums[mid]) {
                // Check if target is bounded within this sorted left half
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Eliminate the right half
                } else {
                    left = mid + 1;  // Eliminate the left half
                }
            } 
            // Otherwise, the right half must be strictly sorted
            else {
                // Check if target is bounded within this sorted right half
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // Eliminate the left half
                } else {
                    right = mid - 1; // Eliminate the right half
                }
            }
        }

        // Target not found
        return -1;
    }
};