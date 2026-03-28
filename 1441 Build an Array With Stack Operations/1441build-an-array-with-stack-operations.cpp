class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int j=0;//index in target

        for(int i=1;i<=n;i++){
            if(j==target.size()) break;   //when the work is doen
            ans.push_back("Push");//we push every element
            if(i==target[j]){
                j++;//we keep it 
            }else{
                ans.push_back("Pop");//remove
            }
        }
        return ans;
    }
};