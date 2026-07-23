class Solution {
public:
    int dfs(int row , int col , vector<vector<int>>& grid){
        if(row<0 || col<0 || row>=grid.size() || col >=grid[0].size() || grid[row][col] == 0){
            return 0;
        }
            grid[row][col] = 0;
            return 1 +
               dfs(row + 1, col, grid) +
               dfs(row - 1, col, grid) +
               dfs(row, col + 1, grid) +
               dfs(row, col - 1, grid);
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxArea = 0;

        for(int i = 0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(grid[i][j]== 1){
                    int area = dfs(i, j, grid);

                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
}; 