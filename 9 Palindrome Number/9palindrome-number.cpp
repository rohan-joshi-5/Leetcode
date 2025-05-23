class Solution {
public:
    bool isPalindrome(int x) {
        int copy = x;
        long long rev;
        if(x<0)
        {
            return false;
        }
        while (x != 0) {
            int rem = x % 10;
            rev = rev * 10 + rem;
            x = x / 10;
        }
        if (rev == copy) {
            return true;
        } else {
            return false;
        }
    }
};