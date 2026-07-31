class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> revadj(V);
        vector<int> indegree(V,0);
        for(int i =0 ; i<V; i++){
            for(int j = 0; j<graph[i].size();j++){

            int neighbour = graph[i][j];
            revadj[neighbour].push_back(i);
            indegree[i]++;
            }
        
        }
        queue<int> q;
        for(int i = 0 ; i<V;i++){
            if(indegree[i]== 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int i = 0 ; i<revadj[node].size();i++){
                int neighbour = revadj[node][i];
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    q.push(neighbour);
                }

            }
        }
        sort(topo.begin(),topo.end());
        return topo;
    }

};