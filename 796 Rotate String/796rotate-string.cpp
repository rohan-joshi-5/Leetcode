class Solution {
public:
    bool rotateString(string s, string goal) {
        // If the strings are not the same length, one cannot be a rotation of the other
        if (s.length() != goal.length()) {
            return false;
        }
        
        // Concatenate s with itself
        string doubled_s = s + s;
        
        // Check if goal is a substring of the doubled string
        return doubled_s.find(goal) != string::npos;
    }
};