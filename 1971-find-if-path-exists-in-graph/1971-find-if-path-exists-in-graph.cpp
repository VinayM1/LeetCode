class Solution {
public:

    void dfs(int node ,  vector<int>& vis , vector<vector<int>>& adj){
        vis[node] = true;
        for(int i = 0 ; i<adj[node].size();i++){
            int neighbour = adj[node][i];
            if(!vis[neighbour]){
                dfs(neighbour,vis,adj);
            }
        }

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i = 0 ; i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        dfs(source, vis, adj); 
        return vis[destination];  
    }
};