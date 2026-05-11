class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        for(int x:nums){
            string s=to_string(x);
            for(char c:s){
                answer.push_back(c-'0');
            }
        }
        return answer;
    }
};