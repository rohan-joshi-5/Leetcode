class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[right]) {
                // Minimum must be to the right
                left = mid + 1;
            } 
            else if (nums[mid] < nums[right]) {
                // Minimum is in the left half (or is mid)
                right = mid;
            } 
            else {
                // nums[mid] == nums[right]
                // We can't be sure which half, but we can safely discard nums[right]
                right--;
            }
        }
        
        return nums[left];
    }
};