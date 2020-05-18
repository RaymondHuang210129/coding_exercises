// meet second times --> delete out that char itself and its previous

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dict; // char, index
        int head = 0;
        int accum = 0;
        int max = 0;
        int str_len = s.length();
        for (int i = 0; i < str_len; i++) {
            accum++;
            auto it = dict.find(s[i]);
            if (it != dict.end() && it->second >= head) {
                accum -= (it->second - head + 1);
                head = it->second + 1;
            }
            dict[s[i]] = i;
            if (accum > max) max = accum;
        }
        return max;
    }
};

