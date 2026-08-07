class Solution {
public:
    int Solve(int index,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount == 0){
            return 1;
        }
        if(index == 0){

            return (amount%coins[0] == 0);
            
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int nottake = Solve(index-1,amount,coins,dp);
        int take = 0;
        if(coins[index]<=amount){
            take = Solve(index,amount-coins[index],coins,dp);
        }
        return dp[index][amount] = take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return Solve(n-1,amount,coins,dp);
    }
};