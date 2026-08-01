class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;

        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int delrow[]= {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!pq.empty()){
            int distance = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 && col == m-1){
                return distance;
            }
            for(int i = 0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    int newEffort = max(distance,abs(heights[row][col] - heights[nrow][ncol]));
                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }

        }
        return dist[n-1][m-1];;

        
    }
};