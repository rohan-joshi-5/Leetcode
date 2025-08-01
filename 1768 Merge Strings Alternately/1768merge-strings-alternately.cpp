class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1=word1.size();
        int l2=word2.size();
        int maxlen=max(l1,l2);
        string merged;
        for(int i=0;i<maxlen;i++){
            if(i<l1) merged+=word1[i];
            if(i<l2) merged+=word2[i];
        }
        return merged;
    }
};