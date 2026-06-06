class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> leftsum;
        vector<int> rightsum(nums.size(),0);
        vector<int> ans;
        if(nums.size()==1){
            ans.push_back(0);
            return ans;
        }
        int sum=0; 
        for(int i=0;i<nums.size();i++){
            leftsum.push_back(sum);//22
            sum=sum+nums[i];
        }
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            rightsum[i]=sum;
            sum=sum+nums[i];
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(abs(leftsum[i]-rightsum[i]));
        }
        return ans;
    }
};