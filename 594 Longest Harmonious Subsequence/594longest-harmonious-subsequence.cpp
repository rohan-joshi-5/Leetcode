class Solution {
public:
    int findLHS(vector<int>& nums) {

        unordered_map<int,int> M;
        for (int x : nums) {
            M[x]++;
        }

        if (M.size() == 1) {
            return 0;
        }

        int maxLen = 0;

        for (auto x : M) {
            if (M.find(x.first - 1) != M.end()) {
                if (maxLen < (x.second + M[x.first - 1])) {
                    maxLen = x.second + M[x.first - 1];
                }
            }

            if (M.find(x.first + 1) != M.end()) {
                if (maxLen < (x.second + M[x.first + 1])) {
                    maxLen = x.second + M[x.first + 1];
                }
            }
        }

        return maxLen;
    }
};
