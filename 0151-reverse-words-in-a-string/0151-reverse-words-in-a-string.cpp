class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i=s.length()-1;
        while(i>=0){
            while(i>=0 && s[i]==' ')//skip spaces
                i--;
            if(i<0)
                break;
            int j=i;

            //move to brgin of current word
            while(i>=0 && s[i]!=' '){
                i--;
            }
            //add space bw words
            if(!ans.empty())
                ans+=" ";

            ans+=s.substr(i+1,j-i);
        }
        return ans;
    }
};