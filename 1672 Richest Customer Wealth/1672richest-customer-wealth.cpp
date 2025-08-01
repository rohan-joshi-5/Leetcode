class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> wealth;
        for(int i = 0;i < accounts.size();i++){
            int value=accounts[i][0];
            for(int j = 1; j<accounts[0].size();j++){
                value=value+accounts[i][j];
            }
            wealth.push_back(value);
        }
        sort(wealth.begin(),wealth.end());
        int x=*max_element(wealth.begin(),wealth.end());
        return x;
    }
};