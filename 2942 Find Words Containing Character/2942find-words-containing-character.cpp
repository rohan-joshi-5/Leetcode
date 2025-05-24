class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n=words.size();
        vector<int> result;
        for(auto i=0;i<n;i++){
            for(auto j:words[i]){
                if(j == x){
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }

};