class Solution {
public:
    int minElement(vector<int>& nums) {
        int min_val = INT_MAX;
        
        for (int num : nums) {
            int current_sum = 0;
            
            // Extract and sum the digits of the current number
            while (num > 0) {
                current_sum += num % 10;
                num /= 10;
            }
            
            // Update the minimum element found so far
            min_val = min(min_val, current_sum);
        }
        
        return min_val;
    }
};