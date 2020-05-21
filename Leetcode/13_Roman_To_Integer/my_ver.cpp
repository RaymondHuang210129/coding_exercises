class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map;
        int len = s.length();
        int total = 0;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        for (int i = len - 1; i >= 0; i--) {
            if (i < len - 1 && map[s[i]] < map[s[i + 1]]) {
                total -= map[s[i]];
            } else {
                total += map[s[i]];
            }
        }
        return total;
    }
};