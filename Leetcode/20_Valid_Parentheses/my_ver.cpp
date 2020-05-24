class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                stack.push_back('(');
            } else if (s[i] == '[') {
                stack.push_back('[');
            } else if (s[i] == '{') {
                stack.push_back('{');
            } else if (s[i] == ')') {
                if (stack.size() > 0 && stack.back() == '(') {
                    stack.pop_back();
                } else {
                    return false;
                }
            } else if (s[i] == ']') {
                if (stack.size() > 0 && stack.back() == '[') {
                    stack.pop_back();
                } else {
                    return false;
                }
            } else if (s[i] == '}') {
                if (stack.size() > 0 && stack.back() == '{') {
                    stack.pop_back();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        if (stack.size()) return false;
        return true;
    }
};