class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& pathVis)
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for(int i = 0; i < adj[node].size(); i++)
        {
            int neighbour = adj[node][i];

            if(!vis[neighbour])
            {
                if(dfs(neighbour, adj, vis, pathVis))
                    return true;
            }
            else if(pathVis[neighbour])
            {
                return true;
            }
        }

        pathVis[node] = 0;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for(int i = 0; i < numCourses; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, adj, vis, pathVis))
                    return false;
            }
        }

        return true;
    }
};