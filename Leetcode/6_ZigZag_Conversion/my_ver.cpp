class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        int period = numRows * 2 - 2;
        string result = "";
        if (numRows == 1) return s;
        for (int i = 0; i <= period / 2; i++) {
            int quo1 = i;
            int quo2 = (period - i) % period;
            for (int j = 0;; j += period) {
                if (j + quo1 >= len) break;
                result += s[j + quo1];
                if (quo1 != quo2) {
                    if (j + quo2 >= len) break;
                    result += s[j + quo2];
                }               
            }
        }
        return result;
    }
};