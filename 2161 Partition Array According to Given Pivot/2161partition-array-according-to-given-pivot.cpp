class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smaller;
        vector<int> larger;
        vector<int> equal;
        for(int it:nums){
            if(it<pivot){
                smaller.push_back(it);
            }
            else if(it>pivot){
                larger.push_back(it);
            }
            else{
                equal.push_back(it);
            }
        }
        for(int i=0;i<smaller.size();i++){
            nums[i]=smaller[i];
        }
        for(int i=0;i<equal.size();i++){
            nums[i+smaller.size()]=equal[i];
        }
        for(int i=0;i<larger.size();i++){
            nums[i+smaller.size()+equal.size()]=larger[i];
        }
        return nums;
    }
};