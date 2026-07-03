class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currmin=prices[0];
        int currentprofit=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            currmin=min(currmin,prices[i]);
            currentprofit=max(currentprofit,prices[i]-currmin);
        }
        return currentprofit;

    }
};