class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        
        // 1. Build a set of all possible prefixes from arr1
        for (int x : arr1) {
            while (x > 0) {
                prefixes.insert(x);
                x /= 10; // Chops off the last digit (e.g., 1234 -> 123)
            }
        }
        
        int maxLength = 0;
        
        // Find the longest matching prefix from arr2
        for (int x : arr2) {
            while (x > 0) {
                // The first match is guaranteed to be the longest for this number
                if (prefixes.count(x)) {
                    int currentLength = to_string(x).length();
                    maxLength = max(maxLength, currentLength);
                    break; // Stop going deeper; move to the next number in arr2
                }
                x /= 10;
            }
        }
        
        return maxLength;
    }
};