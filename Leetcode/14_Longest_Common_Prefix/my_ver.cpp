class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) return "";
        int count = 0;
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].length()) {
                    return strs[0].substr(0, count);
                } else {
                    if (strs[j][i] != strs[0][i]) return strs[0].substr(0, count);
                }
            }
            count++;
        }
        return strs[0].substr(0, count);
    }
};