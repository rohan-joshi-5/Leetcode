class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int left = 0, right = n - 1;
        int insert_here = n - 1;    //start inserting from end
        

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                ans[insert_here] = nums[left] * nums[left];
                left++;
            } else {
                ans[insert_here] = nums[right] * nums[right];
                right--;
            }
            insert_here--;
        }
        return ans;
    }
};
