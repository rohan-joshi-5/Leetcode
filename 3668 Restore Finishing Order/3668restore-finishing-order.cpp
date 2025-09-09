class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int>result;
        unordered_set<int> friendset(friends.begin(),friends.end());
        for(int o:order){
            if(friendset.count(o)) result.push_back(o);
        }
        return result;
    }
};