class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        // Pre-allocate the exact required size to prevent reallocation overhead
        vector<int> ans(2 * n);
        
        for (int i = 0; i < n; ++i) {
            ans[i] = nums[i];                 // Place in the first half
            ans[i + n] = nums[n - i - 1];     // Place in the second half (reversed)
        }
        return ans;
    }
};