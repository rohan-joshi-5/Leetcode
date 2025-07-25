class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> unique(nums.begin(),nums.end());
        int sum=0;
        for(auto i:unique){
            if(i>0){
                sum=sum+i;
            }
        }
        if(sum==0){
            sum=*unique.rbegin();
            return sum;
        }
        return sum;
    }
};