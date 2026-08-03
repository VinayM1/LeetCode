class Disjoint{
    vector<int> rank;
    vector<int> parent;
public:
    Disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0 ; i<=n ; i++){
            parent[i] = i;
        }
    }
    int findUparent(int node){
        if(node == parent[node]){
            return node; 

        }
        return parent[node]=findUparent(parent[node]);//Path Compression directly connectes all with the ultimate parent initally they are connected in order 1->2->3 so as this return intialize it returns 1->2 , 1->3 ,
    }
    void UnionByRank(int u,int v){
        int ulp_u = findUparent(u);//pass u and find the tree with ulitmate parent of u
        int ulp_v = findUparent(v);//pass v and same
        if(ulp_u == ulp_v){
            return;//Already connected as both have same ulitmate parent;
        }
        else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1){
            return -1;
        }
        Disjoint ds(n);
        for(int i = 0 ; i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            ds.UnionByRank(u,v);
            
        }
        int count = 0;
        for(int i = 0;i<n;i++){
            if(ds.findUparent(i)==i){
                count++;
            }
        }
        return count-1;
    }
    
};