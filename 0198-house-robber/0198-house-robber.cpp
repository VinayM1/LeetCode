class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        int prev2 = 0;         // dp[-1]
        int prev1 = nums[0];   // dp[0]

        for(int i = 1; i < n; i++)
        {
            int take = nums[i];

            if(i > 1)
            {
                take += prev2;
            }

            int notTake = prev1;

            int curr = max(take, notTake);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

/*class Solution {
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
};*/