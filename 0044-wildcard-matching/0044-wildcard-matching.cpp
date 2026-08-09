class Solution {
public:

    bool Solve(int i, int j,
               string& s,
               string& p,
               vector<vector<int>>& dp)
    {
        // Both strings finished
        if(i < 0 && j < 0)
        {
            return true;
        }

        // Pattern finished but string remains
        if(j < 0 && i >= 0)
        {
            return false;
        }

        // String finished but pattern remains
        if(i < 0 && j >= 0)
        {
            for(int k = 0; k <= j; k++)
            {
                if(p[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }

        // Memoization
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // Characters match or '?'
        if(s[i] == p[j] || p[j] == '?')
        {
            return dp[i][j] =
                   Solve(i-1, j-1, s, p, dp);
        }

        // '*'
        if(p[j] == '*')
        {
            return dp[i][j] =
                   Solve(i-1, j, s, p, dp) ||
                   Solve(i, j-1, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n,
                               vector<int>(m, -1));

        return Solve(n-1, m-1, s, p, dp);
    }
};