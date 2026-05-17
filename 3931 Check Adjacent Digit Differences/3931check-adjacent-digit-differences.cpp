class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for (int i = 0; i < s.length() - 1; ++i) {
            // Convert characters to their integer values
            int current = s[i] - '0';
            int next = s[i + 1] - '0';
            
            // Check if the absolute difference exceeds 2
            if (abs(current - next) > 2) {
                return false;
            }
        }
        return true;
    }
};