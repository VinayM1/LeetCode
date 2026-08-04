class Solution {
public:
    int Solve(int n, vector<int>& dp){
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n]; //its in the array return it no need to solve it again
        }
        return dp[n] = Solve(n-1,dp) + Solve(n-2,dp);

    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return Solve(n,dp);
        
    }
};