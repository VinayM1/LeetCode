class Solution {
public:
    int Solve(vector<int>& nums,int index,vector<int>& dp){
        int n = nums.size();
        int minsum = INT_MAX;
        if(index>=n-1){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        for(int i = 1; i <= nums[index]; i++) {
            int steps = Solve(nums, index+i, dp);

            if(steps != INT_MAX) {
                minsum = min(minsum, 1 + steps);
            }
        }
        return dp[index] = minsum;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return Solve(nums,0,dp);
    }
};