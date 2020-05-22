class Solution {
public:
    vector<string> table[8] = {vector<string>{"a", "b", "c"},
                               vector<string>{"d", "e", "f"},
                               vector<string>{"g", "h", "i"},
                               vector<string>{"j", "k", "l"},
                               vector<string>{"m", "n", "o"},
                               vector<string>{"p", "q", "r", "s"},
                               vector<string>{"t", "u", "v"},
                               vector<string>{"w", "x", "y", "z"}};
    
    vector<string> letterCombinations(string digits) {
        deque<string> result;
        int len = digits.length();
        if (!len) return vector<string>();
        for (int i = 0; i < len; i++) {
            if (i == 0) {
                for (int j = 0; j < table[digits[i] - '0' - 2].size(); j++) {
                    result.push_back(table[digits[i] - '0' - 2][j]);
                }
            } else {
                while(result.front().length() == i) {
                    string origin = result.front();
                    result.pop_front();
                    for (int j = 0; j < table[digits[i] - '0' - 2].size(); j++) {
                        string newstr = origin + table[digits[i] - '0' - 2][j];
                        result.push_back(newstr);
                    }
                }
            }
        }
        return vector<string>(result.begin(), result.end());
    }
};