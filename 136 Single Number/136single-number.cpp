class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singlenumber=0;
        for(int num:nums){
            singlenumber=singlenumber^num;
        }
        return singlenumber;
    }
};