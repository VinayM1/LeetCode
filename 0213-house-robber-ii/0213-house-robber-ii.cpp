class Solution {
public:
    int solve(vector<int>& nums, int index,int end,vector<int>& dp){
        int n = nums.size();
        if(index>end){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int take = nums[index] + solve(nums,index+2,end,dp);
        int nottake = solve(nums,index+1,end,dp);
        dp[index] = max(nottake,take);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        if(n == 1){
            return nums[0];
        }
        int case1 = solve(nums,0,n-2,dp);
        fill(dp.begin(), dp.end(), -1);
        int case2 = solve(nums,1,n-1,dp);
        return max(case1,case2);
    }
};