class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> seen(password.begin(),password.end());
        int strength=0;
        for(char c :seen){
            if(c>='a' && c<='z'){
                strength++;
            }else if(c>='A' && c<='Z'){
                strength+=2;
            }else if(c>='0' && c<='9'){
                strength+=3;
            }else if(c=='!' || c=='@' || c=='#' || c=='$'){
                strength+=5;
            }
        }
    return strength;
    }
};