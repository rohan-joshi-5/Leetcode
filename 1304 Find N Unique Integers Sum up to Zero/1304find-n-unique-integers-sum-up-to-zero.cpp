class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> sumofzeroes;
        if (n%2==1)sumofzeroes.push_back(0);
        for(int i=1;i<=n/2;i++){
            sumofzeroes.push_back(i);
            sumofzeroes.push_back(-i);
        }
        return sumofzeroes;
    }
};