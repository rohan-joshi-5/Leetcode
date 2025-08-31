class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();
      
        // Initialize result with n (the largest possible missing number)
        // This handles the case where n itself is missing
        int result = n;
      
        // XOR all indices (0 to n-1) and all array elements
        // The XOR operation will cancel out all numbers that appear twice
        // (once as an index and once as an array element)
        // Only the missing number will remain
        for (int i = 0; i < n; ++i) {
            result ^= (i ^ nums[i]);
        }
      
        // Return the missing number
        return result;
    }
};