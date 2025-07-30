class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int n=0;
        for(int i:hours){
            if(i>=target)
            n=n+1;
        }
        return n;
    }
};