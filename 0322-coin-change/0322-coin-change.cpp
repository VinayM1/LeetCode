class Solution {
public:
    int Solve(int index,vector<int>& coins,int amount,vector<vector<int>>& dp){
        if(amount == 0){
            return 0;
        }
        if(index == 0){
            if(amount % coins[0] == 0){
                return amount / coins[0];
            }
            return 1e9;
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int nottake = Solve(index-1,coins,amount,dp);
        int take = 1e9;
        if(coins[index] <= amount){
            take  = 1+ Solve(index, coins, amount - coins[index],dp);
        }
        return dp[index][amount] = min(nottake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = Solve(n-1, coins,amount,dp);
        if(ans >= 1e9)
            return -1;

        return ans;
    }
};