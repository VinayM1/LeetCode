class Disjoint{
    vector<int>size;
    vector<int>parent;
public:
    Disjoint(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUparent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUparent(parent[node]);

    }
    void UnionBySize(int u , int v){
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        if(ulp_u == ulp_v){
            return;
        }
        else if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        Disjoint ds(n);
        int count = 0;
        for(int i = 0 ; i<n;i++){
            for(int j = 0;j<n;j++){
                if(stones[i][0] == stones[j][0] ||
                stones[i][1] == stones[j][1]){
                    ds.UnionBySize(i,j);
                }
            }
        }
        for(int i = 0;i<stones.size();i++){
            if(ds.findUparent(i) == i){
                count++;
            }
        }
        return n-count;
    }
};