class Solution {
public:
    int maxSum(vector<int>& nums, int k) {

        const long long MOD = 1000000007;
        vector<int> bits(32, 0);

        // Count set bits at every position
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < 32; j++) {
                if(nums[i] & (1LL << j)) {
                    bits[j]++;
                }
            }
        }

        long long ans = 0;

        // Construct the k largest possible numbers greedily
        for(int i = 0; i < k; i++) {

            long long num = 0;

            for(int j = 0; j < 32; j++) {
                if(bits[j] > 0) {
                    num |= (1LL << j);
                    bits[j]--;
                }
            }

            ans = (ans + num * num) % MOD;
        }

        return ans;
    }
};