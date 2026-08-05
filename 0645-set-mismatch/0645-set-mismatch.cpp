class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n+1,0);
        for(int x:nums){
            arr[x]++;
        }
        int twice=0,missing=0;
        for(int i=0;i<=n;i++){
            if(arr[i]==2) twice=i;
            if(arr[i]==0) missing=i;
        }
        return{twice,missing};
    }
};