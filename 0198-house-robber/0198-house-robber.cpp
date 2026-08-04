class Solution {
public:
    int Solve(int ind , vector<int>& nums,vector<int>& dp){
        int n = nums.size();
        if(ind == 0)
            return nums[0];

        if(ind < 0)
            return 0;

        if(dp[ind]!=-1)
            return dp[ind];
        
        int take = nums[ind] + Solve(ind-2,nums,dp);
        int nottake = Solve(ind-1,nums,dp);//considering it cause dp consider all cases 
        return dp[ind] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return Solve(n-1,nums,dp);
    }
};