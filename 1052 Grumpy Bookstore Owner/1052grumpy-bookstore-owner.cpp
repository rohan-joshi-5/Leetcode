class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        // 1. Base satisfaction (when owner is not grumpy)
        int base = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                base += customers[i];
            }
        }

        // 2. Sliding window to get max extra customers
        int i = 0, j = 0;
        int windowGain = 0;
        int maxGain = 0;

        while (j < n) {
            // include j
            if (grumpy[j] == 1) {
                windowGain += customers[j];
            }

            // shrink if window size > minutes
            if (j - i + 1 > minutes) {
                if (grumpy[i] == 1) {
                    windowGain -= customers[i];
                }
                i++;
            }

            // update answer when window size == minutes
            if (j - i + 1 == minutes) {
                maxGain = max(maxGain, windowGain);
            }

            j++;
        }

        return base + maxGain;
    }
};
