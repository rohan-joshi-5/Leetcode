class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 4) return false;

        int i = 0;

        // Phase 1: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;
        if (i == 0 || i == n - 1) return false;  // p must be > 0

        int p = i;

        // Phase 2: strictly decreasing
        while (i + 1 < n && nums[i] > nums[i + 1]) i++;
        if (i == p || i == n - 1) return false;  // q must be > p

        int q = i;

        // Phase 3: strictly increasing
        while (i + 1 < n && nums[i] < nums[i + 1]) i++;

        // Final check
        return i == n - 1;
    }
};
