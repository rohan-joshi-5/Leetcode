class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i=0;i<3;i++){
            int j=i+2;
            if(s1[i]!=s2[i]){
                swap(s2[i],s2[j]);
            }
            if(s1==s2){
                return true; 
                break;
            }    
        }
        return false;
    }
};