class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i = 0;i<prerequisites.size();i++){
            int course = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];
            adj[prerequisite].push_back(course);
            indegree[course]++;
            
        }
        queue<int>q;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(int i = 0 ; i<adj[node].size();i++){
                int neighbour = adj[node][i];
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        if(topo.size() == numCourses){
            return topo;
        }
        return{};
    }
};