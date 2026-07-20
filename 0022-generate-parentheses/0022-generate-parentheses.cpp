class Solution {
public:
    vector<string> ans;

    void solve(string current, int open, int close, int n) {

        // Base case
        if (current.length() == 2 * n) {
            ans.push_back(current);
            return;
        }

        // Add '(' if possible
        if (open < n) {
            solve(current + "(", open + 1, close, n);
        }

        // Add ')' if possible
        if (close < open) {
            solve(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        solve("", 0, 0, n);
        return ans;
    }
};