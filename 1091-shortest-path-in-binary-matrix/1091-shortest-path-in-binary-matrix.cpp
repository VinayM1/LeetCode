class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX)); // DIST GRID ALL INFINITY INITIALLY 
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> 
        >pq;
        dist[0][0] = 1; // Marking starting node
        pq.push({1,{0,0}});// pushing in queue using (distance,{row,col})
        int delrow [] = {-1,-1,-1,0,0,1,1,1};
        int delcol [] = {-1,0,1,-1,1,-1,0,1};
        while(!pq.empty()){
            int distance  = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 && col == n-1){
                return distance;
            }
            for(int i = 0;i<8;i++){// i<8 cause 8 directions 
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol] == 0){
                    if(distance+1<dist[nrow][ncol]){
                        dist[nrow][ncol] = distance+1;
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
                

            }
            

        }
        return -1;
        
    }
};