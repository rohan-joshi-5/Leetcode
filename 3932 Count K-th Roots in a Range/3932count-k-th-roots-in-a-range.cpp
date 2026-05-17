class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        // Special case: k=1 means all numbers in range are perfect 1st powers
        if (k == 1) {
            return r - l + 1;
        }

        int count = 0;

        // Iterate through x starting from 0
        for (long long x = 0; ; ++x) {
            long long power = 1;
            bool overflow = false;

            // Calculate x^k manually to avoid floating point precision issues
            for (int i = 0; i < k; ++i) {
                power *= x;
                // If power exceeds r, we can stop checking higher x values
                if (power > r) {
                    overflow = true;
                    break;
                }
            }

            if (overflow) break;

            // Check if x^k falls within the [l, r] range
            if (power >= l) {
                count++;
            }

            // Safety break for x = 0 and x = 1 to prevent infinite loops
            // If x is 0 or 1, and x^k is still less than l, we must move to x = 2
            if (x < 2 && power < l) continue;
            
            // If x is 1 and 1^k (which is 1) is >= l, we don't increment x to 1 
            // indefinitely; the loop continues naturally to x = 2.
        }

        return count;
    }
};