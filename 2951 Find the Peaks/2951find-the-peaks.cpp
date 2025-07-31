class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        int i=0,j=1;
        vector<int> ans;
        while(j+1<mountain.size()){
            if(mountain[i]<mountain[j] && mountain[j]>mountain[j+1]){
                ans.push_back(j);
            }
            j++;
            i++;
        }
        return ans;
    }
};