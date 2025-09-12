class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currentsum=0;
        for(int i=0;i<k;i++)
        {
            currentsum+=nums[i];
        }
        double maxsum=currentsum;
        for(int i=k;i<nums.size();i++)
        {
            currentsum=currentsum+nums[i]-nums[i-k];
            maxsum=max(maxsum,currentsum);
        }
        return maxsum/k;
    }
};