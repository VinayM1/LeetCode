class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<pair<int,int>> adj[n + 1];

        for(int i = 0; i < times.size(); i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;

        pq.push({0, k});

        while(!pq.empty())
        {
            int time = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            for(int i = 0; i < adj[node].size(); i++)
            {
                int neighbour = adj[node][i].first;
                int weight = adj[node][i].second;

                if(time + weight < dist[neighbour])
                {
                    dist[neighbour] = time + weight;

                    pq.push({dist[neighbour], neighbour});
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == INT_MAX)
            {
                return -1;
            }

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};