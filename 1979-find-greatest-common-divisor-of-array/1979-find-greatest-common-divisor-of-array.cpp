class Solution {
public:
    int gcd(int a, int b) {
        int result = min(a, b);
        while (result > 0) {
            if (a % result == 0 && b % result == 0) {
                break;
            }
            result--;
        }
        return result;
    };
    int findGCD(vector<int>& nums) {
        int maxi=INT_MIN,mini=INT_MAX;
        for(int num:nums){
            maxi=max(num,maxi);
            mini=min(num,mini);
        }
        int ans =gcd(maxi,mini);
        return ans;
    }
};