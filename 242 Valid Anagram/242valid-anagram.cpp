class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> charcount(26,0);
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            charcount[s[i]-'a']++;
            charcount[t[i]-'a']--;
        }
        for(int count:charcount){
            if(count!=0) return false;
        }
        return true;
    }
};