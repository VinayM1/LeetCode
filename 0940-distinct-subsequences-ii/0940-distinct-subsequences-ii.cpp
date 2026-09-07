class Solution {
public:
    int distinctSubseqII(string s) {

        const long long MOD = 1000000007;

        long long dp = 1;

        vector<long long> last(26, 0);

        for(int i = 0; i < s.size(); i++) {

            int c = s[i] - 'a';

            long long newDp = (2 * dp - last[c] + MOD) % MOD;

            last[c] = dp;

            dp = newDp;
        }

        return (dp - 1 + MOD) % MOD;
    }
};