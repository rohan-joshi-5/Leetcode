class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int i=0;
        for(int j=0;j<nums.size();j++){
            if(i<k || nums[j]!=nums[i-k]){
                nums[i]=nums[j];
                i++;
            }
        }
        nums.resize(i);
        return nums;
    }
};