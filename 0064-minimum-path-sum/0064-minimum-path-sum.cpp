class Solution {
public:
    int Solve(int row,int col,int m,int n, vector<vector<int>>& grid,vector<vector<int>>& dp){
        
        if(row >= m || col >= n){
            return INT_MAX;
        }
        if(row==m-1 && col==n-1){
            return grid[row][col];
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int down = Solve(row+1,col,m,n,grid,dp);
        int right = Solve(row,col+1,m,n,grid,dp);
        int ans = min(down,right);
        if(ans == INT_MAX){
            return INT_MAX;
        }
        else{
            return dp[row][col] = grid[row][col] + ans;
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return Solve(0,0,m,n,grid,dp);
    }
};