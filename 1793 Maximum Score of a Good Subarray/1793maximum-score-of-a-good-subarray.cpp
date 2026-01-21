class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int i=k,j=k;
        int currentMin=nums[k];
        int score=nums[k];
        while(i>0 || j<(n-1)) //i!=0 ??? because we chek i-1(out of bounds)
        {   
            if (i == 0) {           // left side is NOT available
                j++;
                currentMin = min(currentMin, nums[j]);
            }
            
            else if (j == n - 1) {          //right side is NOT available
                i--;
                currentMin = min(currentMin, nums[i]);
            }
            
            else {                          //. both sides are available
                if (nums[i - 1] > nums[j + 1]) {
                    i--;
                    currentMin = min(currentMin, nums[i]);
                } else {
                    j++;
                    currentMin = min(currentMin, nums[j]);
                }
            }
            score=max(score,currentMin*(j-i+1));
        }
        return score;
    }
};