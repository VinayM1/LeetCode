class Solution {
public:

    int Solve(int i, int j, vector<int>& cuts,
              vector<vector<int>>& dp) {

        // No cut between i and j
        if(i + 1 == j) {
            return 0;
        }

        // Already calculated
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int ans = INT_MAX;

        // Try every possible first cut
        for(int k = i + 1; k < j; k++) {

            int cost = cuts[j] - cuts[i]
                     + Solve(i, k, cuts, dp)
                     + Solve(k, j, cuts, dp);

            ans = min(ans, cost);
        }

        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int>& cuts) {

        // Add boundaries
        cuts.push_back(0);
        cuts.push_back(n);

        // Sort cut positions
        sort(cuts.begin(), cuts.end());

        int c = cuts.size();

        vector<vector<int>> dp(c, vector<int>(c, -1));

        return Solve(0, c - 1, cuts, dp);
    }
};