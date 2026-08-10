class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        
        vector<int> dp(n, 1);

        
        vector<int> prev(n, -1);

        int maxi = 1;
        int lastIndex = 0;

        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {

                if(nums[i] % nums[j] == 0)
                {
                    if(dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        prev[i] = j;
                    }
                }
            }

            
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        
        vector<int> ans;

        while(lastIndex != -1)
        {
            ans.push_back(nums[lastIndex]);
            lastIndex = prev[lastIndex];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};