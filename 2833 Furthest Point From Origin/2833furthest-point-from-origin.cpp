class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int pos=0;
        int count_=0,countL=0,countR=0;
        for(char x:moves){
            if(x=='L'){
                countL++;
            }
            else if(x=='R'){
                countR++;
            }
        }
        count_=moves.length()-(countL+countR);
        return abs(countL-countR)+count_;
    }
};