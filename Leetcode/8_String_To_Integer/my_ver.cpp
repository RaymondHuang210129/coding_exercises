class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        int firstflag = 0;
        int num = 0;
        int sign = 1;
        for (int i = 0; i < len; i++) {
            if (firstflag == 0 && str[i] == 32) {
                continue;
            } else if (firstflag == 0 && str[i] == 45) {
                sign = -1;
                firstflag = 1;
            } else if (firstflag == 0 && str[i] == 43) {
                firstflag = 1;
            } else if (firstflag == 0 && str[i] >= 48 && str[i] <= 57) {
                firstflag = 1;
                num = num * 10 + (str[i] - 48) * sign;
            } else if (firstflag == 1 && str[i] >= 48 && str[i] <= 57) {
                if (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] - 48 > 7)) return INT_MAX;
                if (num < INT_MIN / 10 || (num == INT_MIN / 10 && str[i] - 48 > 8)) return INT_MIN;
                num = num * 10 + (str[i] - 48) * sign;
            } else {
                return num;
            }
        }
        return num;
    }
};