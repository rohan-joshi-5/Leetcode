class Solution {
public:
    string reverseByType(string s) {
        string letters = "";
        string specials = "";

        for (char c : s) {
            if (islower(c)) {
                letters += c;
            } else {
                specials += c;
            }
        }

        reverse(letters.begin(), letters.end());
        reverse(specials.begin(), specials.end());

        string result = s;
        int letterIdx = 0;
        int specialIdx = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (islower(s[i])) {
                result[i] = letters[letterIdx++];
            } else {
                result[i] = specials[specialIdx++];
            }
        }
        return result;
    }
};