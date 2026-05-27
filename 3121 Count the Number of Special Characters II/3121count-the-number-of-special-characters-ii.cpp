class Solution {
public:
    int numberOfSpecialChars(string word) {
        // Use -1 to represent that a character hasn't been seen yet
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);
        
        // Record the specific indices of the characters
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            
            if (c >= 'a' && c <= 'z') {
                // Always overwrite to ensure we have the LAST known position
                lastLower[c - 'a'] = i; 
            } else if (c >= 'A' && c <= 'Z') {
                // Only write if it's the FIRST time we are seeing this uppercase letter
                if (firstUpper[c - 'A'] == -1) {
                    firstUpper[c - 'A'] = i;
                }
            }
        }
        
        int specialCount = 0;
        
        // Count characters that meet the strict ordering condition
        for (int i = 0; i < 26; i++) {
            // Must be present in both cases
            if (lastLower[i] != -1 && firstUpper[i] != -1) {
                // The last lowercase must be strictly BEFORE the first uppercase
                if (lastLower[i] < firstUpper[i]) {
                    specialCount++;
                }
            }
        }
        
        return specialCount;
    }
};