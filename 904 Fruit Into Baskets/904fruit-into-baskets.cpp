class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mpp;
        int count=0,st=0,res=0;
        for(int i=0;i<fruits.size();i++){
            mpp[fruits[i]]++;
            count++;
            while(mpp.size()>2){
                mpp[fruits[st]]--;
                count--;
                if(mpp[fruits[st]]==0) mpp.erase(fruits[st]);
                st++;
            }
            res=max(res,count);
        }
        return res;

        
    }
};