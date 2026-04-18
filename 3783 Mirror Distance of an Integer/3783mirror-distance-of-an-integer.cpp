class Solution {
public:
    int mirrorDistance(int n) {
        int rev_num = 0;
        int cpy=n;
        while (cpy > 0) {
        rev_num = rev_num * 10 + cpy % 10;
        cpy = cpy / 10;
        }
        return abs(n-rev_num);
    }
};