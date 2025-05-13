class Solution {
public:
    int m=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n=s.length();
        vector<int> mpp(26,0);


        for(char &ch:s){
            mpp[ch-'a']++;
        }
        for(int count=1;count<=t;count++){
            vector<int> temp(26,0);

            for(int i=0;i<26;i++){
                char ch = i + 'a';
                int freq = mpp[i];

                if(ch!='z'){
                    temp[(ch+1)-'a']=(temp[(ch+1)-'a']+freq)%m;
                }
                else{
                    temp['a'-'a']=(temp['a' - 'a']+freq)%m;
                    temp['b'-'a']=(temp['b' - 'a']+freq)%m;
                }
            }
            mpp=move(temp);        
        
        }
        int result=0;
        for(int i=0;i<26;i++){
            result=(result + mpp[i])%m;
        }

    return result;
    }
};