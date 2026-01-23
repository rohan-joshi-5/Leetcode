class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int j=0,i=0;
        int ans=INT_MAX;
        int sum=0;
        while(j<n){
            sum+=nums[j];
            //for decreasing the window siz
            while(sum>=target){
                ans=min(ans,(j-i+1));
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return (ans==INT_MAX)?0:ans;

    }
};