class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& rooms){
        vis[node] = true;
        for(int i = 0;i<rooms[node].size();i++){
            int neighbour = rooms[node][i];
            if(!vis[neighbour]){
                dfs(neighbour,vis,rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
            vector<int> vis(rooms.size(), 0);
            dfs(0,vis,rooms);
            for(int i = 0 ; i<rooms.size();i++){
                if(!vis[i]){
                    return false;
                }
            }
            return true;
            
    }
};