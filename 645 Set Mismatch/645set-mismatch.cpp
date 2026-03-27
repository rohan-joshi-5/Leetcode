class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1,0);

        for(int x:nums){
            freq[x]++;
        }
        int miss,dup;
        for(int i = 0;i<=n;i++){
            if(freq[i]==2) dup=i;
            if(freq[i]==0) miss=i;
        }
        return {dup,miss};
    }
};