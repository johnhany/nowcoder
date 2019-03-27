class Solution {
public:
    bool match(char* str, char* pattern)
    {
        int m = 0, n = 0;
        for (char* sitr = str; *sitr != '\0'; ++sitr)
            ++m;
        for (char* pitr = pattern; *pitr != '\0'; ++pitr)
            ++n;
        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (pattern[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.') && dp[i - 1][j]);
                else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.');
        return dp[m][n];
    }
};