class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        int n=words.size();
        int prev_group = -1;
        for(int i=0;i<n;i++)
        {
            if(groups[i]!=prev_group)
            {
                result.push_back(words[i]);
                prev_group=groups[i];
            }
        }
        return result;
    }
};