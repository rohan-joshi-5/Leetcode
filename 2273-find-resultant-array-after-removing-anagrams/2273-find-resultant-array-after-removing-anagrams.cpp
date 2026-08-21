class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string prev;
        for (string str:words) {
            string temp=str;
            sort(temp.begin(),temp.end());
            if (temp != prev) {
                ans.push_back(str);
            }
                prev=temp;
        }
        return ans;
    }
};