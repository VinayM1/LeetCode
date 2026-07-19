class Solution {
public:
    const long long MOD = 1000000007;

    long long power(long long x, long long n) {
        if (n == 0)
            return 1;

        long long half = power(x, n / 2);

        long long ans = (half * half) % MOD;

        if (n % 2 == 1)
            ans = (ans * x) % MOD;

        return ans;
    }

    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long evenWays = power(5, even);
        long long oddWays = power(4, odd);

        return (evenWays * oddWays) % MOD;
    }
};