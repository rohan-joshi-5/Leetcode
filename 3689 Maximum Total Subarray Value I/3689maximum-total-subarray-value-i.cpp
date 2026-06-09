class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int global_min = INT_MAX;
        int global_max = INT_MIN;
        
        // Find the global minimum and maximum elements in the array
        for (int num : nums) {
            if (num < global_min) global_min = num;
            if (num > global_max) global_max = num;
        }
        
        // Calculate the maximum value achievable by a single subarray
        long long max_subarray_value = global_max - global_min;
        
        // Since we can repeat the same optimal subarray k times, multiply by k
        return max_subarray_value * k;
    }
};