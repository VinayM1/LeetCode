class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<pair<int,int>, int>> q;
        vector<vector<int>> vis(rows, vector<int>(cols, 0));

        int fresh = 0;

        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {

                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                else {
                    vis[i][j] = 0;
                }

                if(grid[i][j] == 1)
                    fresh++;
            }
        }

        int time = 0;

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while(!q.empty()) {

            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            time = max(time, t);

            for(int i = 0; i < 4; i++) {

                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < rows &&
                   ncol >= 0 && ncol < cols &&
                   !vis[nrow][ncol] &&
                   grid[nrow][ncol] == 1)
                {
                    vis[nrow][ncol] = 1;
                    fresh--;

                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }

        if(fresh != 0)
            return -1;

        return time;
    }
};