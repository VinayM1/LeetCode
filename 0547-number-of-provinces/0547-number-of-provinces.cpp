class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected, vector<int>& vis ){
        vis[node] = true;
        for(int i = 0 ; i<isConnected.size();i++){
                int neighbour = i;
                if(isConnected[node][i] == 1 && !vis[neighbour]){
                    dfs(neighbour,isConnected,vis);

                
                }   
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(), 0);
        int provience = 0;
        for(int i = 0; i<isConnected.size();i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                provience++;
            }
        }
        return provience;
       
    }
};