class Solution {
public:
    int ans = 0;
    int solve(vector<int>& nums , int index,vector<int>& dp){
        int n = nums.size();
        if(index >= n){
            return 0;
        }
        if(dp[index]!= -1){
            return dp[index];
        }
        
        int take = nums[index] + solve(nums,index+2,dp);
        int nottake = solve(nums,index+1,dp);
        return dp[index] =  max(nottake,take);
        
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,0,dp);
   }
};