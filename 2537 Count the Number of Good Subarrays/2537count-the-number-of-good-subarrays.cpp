class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        long long result=0;
        unordered_map<int,int> mp;
        long long pairs=0;
        while(j<n){
            pairs+=mp[nums[j]];         //how many times have we encountered this element
            mp[nums[j]]++;              //after that we update the freq in map
            while(pairs>=k){
                result+=(n-j);  //add the corresponding subarr(s) in result;all the elements after a valid subarr are subarrays
                mp[nums[i]]--;//update the freq in map by removing ith element
                pairs-=mp[nums[i]];
                i++;
            }
            j++;
        }
        return result;
    }
};