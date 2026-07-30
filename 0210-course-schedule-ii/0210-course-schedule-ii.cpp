class Solution {
public:

    bool dfs(int node,
             vector<vector<int>>& adj,
             vector<int>& vis,
             vector<int>& pathVis,
             vector<int>& topo)
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for(int i = 0; i < adj[node].size(); i++)
        {
            int neighbour = adj[node][i];

            if(!vis[neighbour])
            {
                if(dfs(neighbour, adj, vis, pathVis, topo))
                    return true;
            }
            else if(pathVis[neighbour])
            {
                return true;
            }
        }

        pathVis[node] = 0;

        topo.push_back(node);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(numCourses);

        for(int i = 0; i < prerequisites.size(); i++)
        {
            int course = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];

            adj[prerequisite].push_back(course);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        vector<int> topo;

        for(int i = 0; i < numCourses; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, adj, vis, pathVis, topo))
                    return {};
            }
        }

        reverse(topo.begin(), topo.end());

        return topo;
    }
};