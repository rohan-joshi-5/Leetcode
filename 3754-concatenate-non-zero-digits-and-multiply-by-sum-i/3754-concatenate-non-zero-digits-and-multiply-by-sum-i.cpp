class Solution {
public:
    long long sumAndMultiply(int n) {
        long long multiplier=1,sumofdigits=0;
        long long sum=0;
        while(n>0){
            int lastDigit=n%10;
            if(lastDigit!=0){
                sum+=lastDigit*multiplier;
                sumofdigits+=lastDigit;
                multiplier*=10;
            }
            n/=10;
        }
        return sumofdigits*sum;
    }
};