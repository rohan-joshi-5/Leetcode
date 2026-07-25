class Solution {
public:
//1234 567
//4321 567
//4321 765
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int j=nums.size()-k;
        int i=0;
        if (k==0||nums.size()==1) return;
        reverse(nums.begin(),nums.end()-k);
        reverse(nums.begin()+j,nums.end());
        reverse(nums.begin(),nums.end());
        return;
    }
};