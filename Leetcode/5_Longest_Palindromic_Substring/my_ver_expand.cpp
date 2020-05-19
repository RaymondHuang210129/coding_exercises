class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int max = 0;
        string result = "";
        for (int i = 0; i < len; i++) {
            // axis on char
            int expand = 0;
            int plen = 1;
            while (i - expand >= 0 && i + expand < len && s[i - expand] == s[i + expand]) {
                if (plen > max) {
                    max = plen;
                    result = s.substr(i - expand, plen);
                }
                plen += 2;
                expand++;
            }
            // axis between chars
            expand = 0;
            plen = 2;
            while (i - expand >= 0 && i + 1 + expand < len && s[i - expand] == s[i + expand + 1]) {
                if (plen > max) {
                    max = plen;
                    result = s.substr(i - expand, plen);
                }
                plen += 2;
                expand++;
            }
        }
        return result;
    }
};