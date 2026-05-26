class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count=0;
        vector<bool> lowerSeen(26,false);
        vector<bool> upperSeen(26,false);

        for(char c: word){
            if(c >= 'a' && c <= 'z'){
                lowerSeen[c-'a'] = true;
            }else if(c >= 'A' && c <= 'Z'){
                upperSeen[c-'A']=true;
            }
        }
        for(int i=0;i<26;i++){
            if(lowerSeen[i] && upperSeen[i]){
                count++;
            }
        }
        return count;

    }
};