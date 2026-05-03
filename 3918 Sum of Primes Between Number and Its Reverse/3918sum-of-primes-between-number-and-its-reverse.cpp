class Solution {
public:
    bool isPrime(int num){
        if(num<=1)return false;
        if(num<=3)return true;
        if(num%2==0 || num%3==0)return false;
        for(int i=5;i*i<=num;i+=6){
            if(num%i==0 || num%(i+2)==0){
                return false;
            }
        }
        return true;
    }
    
    int sumOfPrimesInRange(int n) {
        int reversed_n=0;
        int temp=n;
        while(temp>0){
            reversed_n=reversed_n*10+temp%10;
            temp/=10;
        }
        int lower_bound = min(n,reversed_n);
        int upper_bound = max(n,reversed_n);
        long long prime_sum= 0;
        for(int i =lower_bound;i<=upper_bound;i++){
            if(isPrime(i)){
                prime_sum+=i;
            }
        }
        return prime_sum;
    }
};