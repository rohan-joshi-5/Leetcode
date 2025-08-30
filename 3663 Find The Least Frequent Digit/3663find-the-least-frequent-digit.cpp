class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> freq(10, 0);
        while (n > 0) {
            int digit = n % 10;
            freq[digit]++;
            n /= 10;
        }
        int minfreq = INT_MAX;
        int result = 0;
        for (int i = 0; i< 10; i++) {
            if (freq[i] > 0 && freq[i] < minfreq) {
                minfreq = freq[i];
                result = i;
            }
        }
        return result;
    }
};
