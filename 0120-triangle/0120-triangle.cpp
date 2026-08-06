class Solution {
public:
    int Solve(int row,int col,int n,
              vector<vector<int>>& triangle,
              vector<vector<int>>& dp){

        if(row == n-1){
            return dp[row][col] = triangle[row][col];
        }

        if(dp[row][col] != INT_MAX){
            return dp[row][col];
        }

        int down = Solve(row+1,col,n,triangle,dp);
        int diag = Solve(row+1,col+1,n,triangle,dp);

        return dp[row][col] =
               triangle[row][col] + min(down,diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n,INT_MAX));

        return Solve(0,0,n,triangle,dp);
    }
};