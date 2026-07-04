class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        int longest=1;
        unordered_set<int>set;
        for(int num:nums){
            set.insert(num);
        }
        for(auto it:set){
            if(set.find(it-1)==set.end()){//element does not exist it may be first number of seq
                int cnt=1;
                int x=it;
                while(set.find(x+1)!=set.end()){
                    x=x+1;
                    cnt++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};