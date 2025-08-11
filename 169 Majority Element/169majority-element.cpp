class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int current_element=0,count=0;
        for (int num:nums){
            if(count==0){
                current_element=num;
                count++;
            }
            else if(current_element==num){
                count++;
            }
            else count--;
        }
        return current_element;
    }
};