class Solution {
public:
    int Solve(int index,int buy ,int cap, vector<int>& prices,vector<vector<vector<int>>>& dp){
        int n = prices.size();
        int profit = 0;
        if(cap == 0){
            return 0;
        }
        if(index == n){
            return 0;
        }
        if(dp[index][buy][cap] != -1){
            return dp[index][buy][cap];
        }
        if(buy){
            profit = max(-prices[index] + Solve(index+1,0,cap,prices,dp) , 0 + Solve(index+1,1,cap,prices,dp));
        }
        else{
            profit = max(prices[index] + Solve(index+1,1,cap-1,prices,dp),0 + Solve(index+1,0,cap,prices,dp));
        }
        return dp[index][buy][cap]= profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k + 1, -1)));
        return Solve(0,1,k,prices,dp);

    }
};