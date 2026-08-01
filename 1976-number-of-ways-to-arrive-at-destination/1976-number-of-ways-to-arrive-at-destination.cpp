class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<pair<int,int>> adj[n];
        for(int i = 0; i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        priority_queue<
        pair<long long,int>,
        vector<pair<long long,int>>,
        greater<pair<long long,int>>
        > pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            long long distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(distance > dist[node]){
                continue;
            }
            for(int i = 0; i<adj[node].size() ; i++){
                int neighbour = adj[node][i].first;
                int weight = adj[node][i].second;
                if(distance+weight < dist[neighbour]){
                    dist[neighbour] = distance+weight;
                    pq.push({dist[neighbour], neighbour});
                    ways[neighbour] = ways[node];
                }
                else if(distance+weight == dist[neighbour]){
                    ways[neighbour] = (ways[neighbour] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};