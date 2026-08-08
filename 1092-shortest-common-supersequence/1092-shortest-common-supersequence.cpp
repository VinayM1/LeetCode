class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        // LCS DP Table
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill DP Table
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string ans = "";

        int i = n;
        int j = m;

        // Backtracking
        while(i > 0 && j > 0)
        {
            // Characters match
            if(str1[i - 1] == str2[j - 1])
            {
                ans += str1[i - 1];
                i--;
                j--;
            }
            // Move Up
            else if(dp[i - 1][j] > dp[i][j - 1])
            {
                ans += str1[i - 1];
                i--;
            }
            // Move Left
            else
            {
                ans += str2[j - 1];
                j--;
            }
        }

        // Remaining characters of str1
        while(i > 0)
        {
            ans += str1[i - 1];
            i--;
        }

        // Remaining characters of str2
        while(j > 0)
        {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};