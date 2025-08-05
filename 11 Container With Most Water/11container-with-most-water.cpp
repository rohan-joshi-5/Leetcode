class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int area=0,maxi=0;
        while(i<j){
            area=min(nums[i],nums[j])*(j-i);
            if(nums[i]<nums[j]) i++;
            else j--;
            maxi=max(area,maxi);
        }
        return maxi;
        
    }
};