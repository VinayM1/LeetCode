class Solution {
public:
    long long countCommas(int n) {

        long long ans = 0;

        long long start = 1000;
        long long commas = 1;

        while(start <= n) {

            long long end = start * 1000 - 1;

            long long last = min((long long)n, end);

            long long count = last - start + 1;

            ans += count * commas;

            start = start * 1000;
            commas++;
        }

        return ans;
    }
};