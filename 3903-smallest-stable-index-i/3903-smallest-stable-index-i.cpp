class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            int maxVal = INT_MIN;
            int minVal = INT_MAX;

            // Find maximum from 0 to i
            for(int j = 0; j <= i; j++) {
                maxVal = max(maxVal, nums[j]);
            }

            // Find minimum from i to n-1
            for(int j = i; j < n; j++) {
                minVal = min(minVal, nums[j]);
            }

            if(maxVal - minVal <= k) {
                return i;
            }
        }

        return -1;
    }
};