class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , vector<int>>mp;//number->vector{indices}

        int result=INT_MAX;

        for(int k=0;k<n;k++){
            mp[nums[k]].push_back(k);
            if(mp[nums[k]].size()>=3){
                //i,j,k
                //2*(k-i)
                vector<int> &vec =mp[nums[k]];
                int size=vec.size();

                int i=vec[size-3];//{.....i,j,k} to access 3rd last element

                result=min(result,(k-i));
            }
        }
        return result==INT_MAX ? -1 : 2*result;


    }
};