class Solution {
public:
    string intToRoman(int num) {
        vector<vector<int>> table(4, vector<int>(3, 0));
        char symbol[4][3] = {'I', 'V', 'I', 
                             'X', 'L', 'X',
                             'C', 'D', 'C',
                             'M', '?', 'M'};
        string result = "";
        for (int i = 0; num > 0; i++) {
            int digit = num % 10;
            if (digit % 5 == 4) {
                table[i][2] = 1;
            } else {
                table[i][0] = digit % 5;
            }
            if ((digit + 1) / 5) {
                table[i][1] = (digit + 1) / 5;
            }
            num /= 10;
        }
        for (int i = 3; i >= 0; i--) {
            for (int j = 2; j >= 0; j--) {
                if (j == 1 && table[i][j] == 2) {
                    result += string(1, symbol[i + 1][0]);
                } else {
                    result += string(table[i][j], symbol[i][j]);
                }
            }
        }
        return result;
        
    }
};