class Solution {
public:
    int minInsertions(string s) {

        int open = 0;
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                open++;
            }
            else {

                // If the next character is also ')',
                // we have a complete closing pair.
                if(i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                }
                else {
                    // Insert one ')' to complete the pair.
                    ans++;
                }

                // Use one opening '(' for this closing pair.
                if(open > 0) {
                    open--;
                }
                else {
                    // Insert one '(' because no opening exists.
                    ans++;
                }
            }
        }

        // Every remaining '(' needs two closing ')'.
        ans += open * 2;

        return ans;
    }
};