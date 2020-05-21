class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.length();
        int plen = p.length();
        vector<vector<bool>> table(slen + 1, vector<bool>(plen + 1, false));
        for (int i = 0; i <= slen; i++) {
            for (int j = 0; j <= plen; j++) {
                if (!i && !j) {
                    table[i][j] = true;
                } else if (j && p[j - 1] == '*') {
                    table[i][j] = j > 1 && (table[i][j - 2] || (i > 0 && table[i - 1][j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1])));
                } else {
                    table[i][j] = i > 0 && j > 0 && table[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return table[slen][plen];
    }
};