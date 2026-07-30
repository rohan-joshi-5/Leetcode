class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            int num=target-nums[i];
            if(mpp.count(num)){
                return {mpp[num],i};
            }
            mpp[nums[i]]=i;
        }
        return{};
    }
};