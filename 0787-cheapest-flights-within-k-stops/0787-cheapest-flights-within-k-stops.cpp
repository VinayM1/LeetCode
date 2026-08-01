class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int,int>> adj[n];

        for(int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];

            adj[u].push_back({v,cost});
        }

        queue<pair<int,pair<int,int>>> q;

        vector<int> dist(n, INT_MAX);

        dist[src] = 0;

        q.push({0,{src,0}});

        while(!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;

            q.pop();

            if(stops > k)
                continue;

            for(int i = 0; i < adj[node].size(); i++)
            {
                int neighbour = adj[node][i].first;
                int edgeCost = adj[node][i].second;

                if(cost + edgeCost < dist[neighbour] && stops <= k)
                {
                    dist[neighbour] = cost + edgeCost;

                    q.push({stops + 1,{neighbour,dist[neighbour]}});
                }
            }
        }

        if(dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};