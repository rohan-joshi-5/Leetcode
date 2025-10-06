class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        int i = s.size() - 1; // i = 1
        while (i >= 0 && s[i] == ' ')
            i--; // skip trailing space → i = 0
        while (i >= 0 && s[i] != ' ') {
            count++; // count 'a'
            i--;
        }
        return count;
    }
};