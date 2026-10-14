class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });

        int n = nums.size();
        long long ans = 0;

        for(int i = 0; i < n; i++) {

            long long square = 1LL * nums[i] * nums[i];

            if(i < n / 2) {
                ans -= square;
            }
            else {
                ans += square;
            }
        }

        return ans;
    }
};