class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>freq;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            int num = target - nums[i];
            if(freq.count(num))
            {
                return {freq[num] , i};
            }

            freq[nums[i]] = i;
        }
    return {};   
    }
};