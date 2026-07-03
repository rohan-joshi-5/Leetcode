class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int>neg;
        for(int i:nums){
            if(i<0){
                neg.push_back(i);
            }else{
                pos.push_back(i);
            }
        }
        int n=nums.size();
        for(int i = 0; i < pos.size(); i++){
            nums[2 * i] = pos[i];      //even
            nums[2 * i + 1] = neg[i];  //odd
        }
        return nums;
    }
};