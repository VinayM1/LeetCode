class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int xr = 0;

        // XOR of the entire array
        for(int i = 0; i < n; i++) {
            xr ^= nums[i];
        }

        // Entire array already has non-zero XOR
        if(xr != 0) {
            return n;
        }

        // Total XOR is 0.
        // If there is any non-zero element,
        // remove it and remaining XOR becomes non-zero.
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) {
                return n - 1;
            }
        }

        // Every element is zero
        return 0;
    }
};