class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        int length=0;
        int maxlength=0;
        int numberofzeroes=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]==0){
                numberofzeroes++;
            }
            while(numberofzeroes>k){
                if(nums[left]==0) numberofzeroes--;
                left++;
            }
            length=right-left+1;
            maxlength=max(maxlength,length);
        }
        return maxlength;
    }
};