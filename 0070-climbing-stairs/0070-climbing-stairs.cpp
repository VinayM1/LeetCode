//Space Optimized DP/ Tabulation Method T(C) -> O(N) , S(C) -> 0(1)
class Solution {
public:
    int climbStairs(int n) {

        if(n == 0)
            return 1;

        if(n == 1)
            return 1;

        int prev2 = 1;   // dp[0]
        int prev1 = 1;   // dp[1]

        for(int i = 2; i <= n; i++)
        {
            int curr = prev1 + prev2;

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

//Memoization Code T(C)/S(C) = O(N)
/*class Solution {
public:

    int solve(int n, vector<int>& dp)
    {
        if(n == 0)
            return 1;

        if(n == 1)
            return 1;

        if(dp[n] != -1)
            return dp[n];

        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }

    int climbStairs(int n)
    {
        vector<int> dp(n+1, -1);

        return solve(n, dp);
    }
};*/