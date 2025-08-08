class Solution {
public:
    string getHint(string secret, string guess) {
        int x=0,y=0;
        vector<int> bcount(10,0);//{0,1,0,0,0,0,0,0,0,0}
        vector<int> ccount(10,0);
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]) x++;
            else{
                bcount[secret[i]-'0']++;
                ccount[guess[i]-'0']++;
            }
        }
        for(int i=0;i<10;i++){
            y+=min(bcount[i],ccount[i]);
        }
        return to_string(x)+"A"+to_string(y)+"B";


    }
};