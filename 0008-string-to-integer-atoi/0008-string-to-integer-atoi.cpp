class Solution {
public:

    int solve(string &s, int i, long long num, int sign) {

        // End of string
        if (i == s.length()) {

            num *= sign;

            if (num > INT_MAX)
                return INT_MAX;

            if (num < INT_MIN)
                return INT_MIN;

            return (int)num;
        }

        // Current character is digit
        if (s[i] >= '0' && s[i] <= '9') {

            num = num * 10 + (s[i] - '0');

            if (sign == 1 && num > INT_MAX)
                return INT_MAX;

            if (sign == -1 && -num < INT_MIN)
                return INT_MIN;

            return solve(s, i + 1, num, sign);
        }

        // First invalid character
        num *= sign;

        if (num > INT_MAX)
            return INT_MAX;

        if (num < INT_MIN)
            return INT_MIN;

        return (int)num;
    }

    int myAtoi(string s) {

        int i = 0;

        // Skip spaces
        while (i < s.length() && s[i] == ' ')
            i++;

        int sign = 1;

        // Sign
        if (i < s.length()) {

            if (s[i] == '-') {
                sign = -1;
                i++;
            }
            else if (s[i] == '+') {
                i++;
            }
        }

        return solve(s, i, 0, sign);
    }
};