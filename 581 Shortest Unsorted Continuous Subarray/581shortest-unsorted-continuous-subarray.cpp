class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int end = -1;
        int max_val = nums[0];
        // Find the rightmost element that is smaller than the max seen so far
        for (int i = 1; i < n; i++) {
            if (max_val > nums[i]) {
                end = i;
            } else {
                max_val = nums[i];
            }
        }
        // If end is still -1, the array is already sorted
        if (end == -1) return 0;
        int start = 0;
        int min_val = nums[n - 1];
        // Find the leftmost element that is larger than the min seen so far
        for (int i = n - 2; i >= 0; i--) {
            if (min_val < nums[i]) {
                start = i;
            } else {
                min_val = nums[i];
            }
        }
        return end - start + 1;
    }
};