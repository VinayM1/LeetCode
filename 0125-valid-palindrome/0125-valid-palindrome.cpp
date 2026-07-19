class Solution {
public:

    bool solve(string &s, int left, int right){

        if(left >= right)
            return true;

        if(!isalnum(s[left]))
            return solve(s, left + 1, right);

        if(!isalnum(s[right]))
            return solve(s, left, right - 1);

        if(tolower(s[left]) != tolower(s[right]))
            return false;

        return solve(s, left + 1, right - 1);
    }

    bool isPalindrome(string s) {

        return solve(s, 0, s.size() - 1);

    }
};