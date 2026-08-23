class Solution {
public:
    bool checkValidString(string s) {
        int minCount = 0;
        int maxCount = 0;

        for (char c : s) {

            if (c == '(') {
                minCount++;
                maxCount++;
            }

            else if (c == ')') {
                minCount--;
                maxCount--;
            }

            else { // '*'
                minCount--; // '*' = ')'
                maxCount++; // '*' = '('
            }

            // Even the maximum possible count is negative
            if (maxCount < 0) {
                return false;
            }

            // Minimum cannot go below 0
            minCount = max(0, minCount);
        }

        return minCount == 0;
    }
};