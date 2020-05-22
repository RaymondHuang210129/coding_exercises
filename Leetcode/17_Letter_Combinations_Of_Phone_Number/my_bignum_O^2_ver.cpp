class Solution {
public:
    vector<char> table[8] = {vector<char>{'a', 'b', 'c'},
                             vector<char>{'d', 'e', 'f'},
                             vector<char>{'g', 'h', 'i'},
                             vector<char>{'j', 'k', 'l'},
                             vector<char>{'m', 'n', 'o'},
                             vector<char>{'p', 'q', 'r', 's'},
                             vector<char>{'t', 'u', 'v'},
                             vector<char>{'w', 'x', 'y', 'z'}};
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int len = digits.length();
        if (!len) return result;
        vector<int> accum(len, 0);
        do {
            string str = "";
            for (int i = 0; i < len; i++) {
                str += table[digits[i] - '0' - 2][accum[i]];
            }
            result.push_back(str);
        } while(add(accum, digits));
        return result;
    }
    
    bool add(vector<int>& accum, string digits) {
        int carry = 1;
        int len = accum.size();
        for (int i = len - 1; i >= 0; i--) {
            if (i == 0) {
                if (accum[i] + carry >= table[digits[i] - '0' - 2].size()) {
                    return false;
                } else {
                    accum[i] += carry;
                    carry = 0;
                }
            } else {
                if (accum[i] + carry >= table[digits[i] - '0' - 2].size()) {
                    accum[i] = 0;
                    carry = 1;
                } else {
                    accum[i] += carry;
                    carry = 0;
                }
            }
        }
        return true;
    }
};