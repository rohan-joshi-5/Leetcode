class Solution {
public://{0,1,2,2,1,0,0,1,1}
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n+1,0);
        vector<int> result;
        for(int num : nums){
            count[num]++;
            if(count[num] == 2) result.push_back(num);
        }
        return result;

    }
};