class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        
        // Quick check: If the destination itself is '1', we can never land on it.
        if (s[n - 1] == '1') return false;

        // dp[i] indicates whether we can successfully reach index i
        vector<bool> dp(n, false);
        dp[0] = true; // We start at index 0, so it's always reachable

        int activeReachable = 0; // Tracks the number of valid jump points in our current window

        for (int i = 1; i < n; ++i) {
            // 1. A new index enters our valid jump window [i - maxJump, i - minJump]
            if (i >= minJump) {
                if (dp[i - minJump]) {
                    activeReachable++;
                }
            }

            // 2. An old index falls out of the back of our valid jump window
            if (i > maxJump) {
                if (dp[i - maxJump - 1]) {
                    activeReachable--;
                }
            }

            // 3. Evaluate the current position
            // If it's a '0' and we have at least one valid point to jump from, we can reach it
            if (s[i] == '0' && activeReachable > 0) {
                dp[i] = true;
            }
        }

        // The answer is whether the last index is reachable
        return dp[n - 1];
    }
};