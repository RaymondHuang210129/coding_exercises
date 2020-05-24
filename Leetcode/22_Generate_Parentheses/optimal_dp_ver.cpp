class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> dp[n + 1];
        dp[0].push_back("");
        for (int i = 1; i <= n; i++) {
            for (int k = 0; k < i; k++) {
                for (int m = 0; m < dp[k].size(); m++) {
                    for (int n = 0; n < dp[i - k - 1].size(); n++) {
                        dp[i].push_back("(" + dp[k][m] + ")" + dp[i - k - 1][n]);
                    }
                }
            }
        }
        return dp[n];
    }
};