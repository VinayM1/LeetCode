class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        if(sum % 2 != 0)
        {
            return false;
        }

        int target = sum / 2;

        vector<bool> prev(target + 1, false);

        // Base Case 1
        prev[0] = true;

        // Base Case 2
        if(nums[0] <= target)
        {
            prev[nums[0]] = true;
        }

        for(int index = 1; index < n; index++)
        {
            vector<bool> curr(target + 1, false);

            curr[0] = true;

            for(int t = 1; t <= target; t++)
            {
                bool notTake = prev[t];

                bool take = false;

                if(nums[index] <= t)
                {
                    take = prev[t - nums[index]];
                }

                curr[t] = take || notTake;
            }

            prev = curr;
        }

        return prev[target];
    }
};
/*class Solution {
public:
    bool Solve(int index,int target, vector<int>& nums,vector<vector<int>>& dp){
        
        if(target == 0)
            return true;

        if(index == 0)
            return nums[0] == target;

        if(dp[index][target] != -1){
            return dp[index][target];
        }

        bool nottake =  Solve(index-1,target,nums,dp);
        bool take = false;
        if(target>=nums[index]){
            take = Solve(index-1,target-nums[index],nums,dp);
        }
        return dp[index][target] = nottake || take;
    }
    bool canPartition(vector<int>& nums ) {
        int n = nums.size();
        
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
        }
        if(sum %2 != 0){
            return false;
        }
        int target = sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return Solve(nums.size()-1,target,nums,dp);
    }
};*/