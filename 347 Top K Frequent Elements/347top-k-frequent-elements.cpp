class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        priority_queue<pair<int,int>> pq;
        vector <int> result;
        for(auto i : nums){
            map[i]++;
        }
        for(pair<int,int>i:map){
            int element=i.first;
            int freq=i.second;
            pq.push({freq,element});
        }
        for (int i=0;i<k;i++){
            pair<int,int>res = pq.top();
            pq.pop();
            result.push_back(res.second);
        }
        return result;
        

    }
};