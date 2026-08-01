class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<pair<pair<int,int>,int>> q;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = 1;

        q.push({{0,0},1});

        int delRow[] = {-1,-1,-1,0,0,1,1,1};
        int delCol[] = {-1,0,1,-1,1,-1,0,1};

        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int distance = q.front().second;

            q.pop();

            if(row == n-1 && col == n-1)
                return distance;

            for(int i = 0; i < 8; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow >= 0 &&
                   ncol >= 0 &&
                   nrow < n &&
                   ncol < n &&
                   grid[nrow][ncol] == 0 &&
                   distance + 1 < dist[nrow][ncol])
                {
                    dist[nrow][ncol] = distance + 1;

                    q.push({{nrow,ncol}, distance + 1});
                }
            }
        }

        return -1;
    }
};