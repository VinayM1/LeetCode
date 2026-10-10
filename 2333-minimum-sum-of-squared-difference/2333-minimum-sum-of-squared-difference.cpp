class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<long long> diff(n);

        long long total = 0;

        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
        }

        if(total <= k) {
            return 0;
        }

        sort(diff.begin(), diff.end());

        long long left = 0;
        long long right = diff[n - 1];

        while(left < right) {
            long long mid = left + (right - left) / 2;

            long long needed = 0;

            for(int i = 0; i < n; i++) {
                if(diff[i] > mid) {
                    needed += diff[i] - mid;
                }
            }

            if(needed <= k) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        long long level = left;
        long long used = 0;
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            if(diff[i] > level) {
                used += diff[i] - level;
                diff[i] = level;
            }
        }

        long long remaining = k - used;

        for(int i = 0; i < n && remaining > 0; i++) {
            if(diff[i] == level && level > 0) {
                diff[i]--;
                remaining--;
            }
        }

        for(int i = 0; i < n; i++) {
            ans += diff[i] * diff[i];
        }

        return ans;
    }
};