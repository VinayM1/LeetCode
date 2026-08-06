class Solution {
public:
    int Solve(int row , int col , vector<vector<int>>& obstacleGrid , vector<vector<int>>& dp){
        if(row<0 || col<0){
            return 0;
        }
        if(obstacleGrid[row][col] == 1){
            return 0;
        }
        if(row == 0 && col == 0){
            return 1;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        
        int up = Solve(row-1,col,obstacleGrid,dp);
        int left = Solve(row,col-1,obstacleGrid,dp);
        return dp[row][col] =  up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return Solve(row-1,col-1,obstacleGrid,dp);
    }
};