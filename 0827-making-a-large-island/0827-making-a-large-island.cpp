class Disjoint {
    vector<int> parent, size;

public:
    Disjoint(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void UnionBySize(int u, int v) {

        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    int getSize(int node) {
        return size[findUPar(node)];
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        Disjoint ds(n * n);

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        //  Connect all existing islands
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(grid[row][col] == 0)
                    continue;

                for(int k = 0; k < 4; k++)
                {
                    int nrow = row + delRow[k];
                    int ncol = col + delCol[k];

                    if(nrow >= 0 && ncol >= 0 &&
                       nrow < n && ncol < n &&
                       grid[nrow][ncol] == 1)
                    {
                        int node = row * n + col;
                        int adjNode = nrow * n + ncol;

                        ds.UnionBySize(node, adjNode);
                    }
                }
            }
        }

        int ans = 0;

        //  Change every 0 into 1
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(grid[row][col] == 1)
                    continue;

                set<int> components;

                for(int k = 0; k < 4; k++)
                {
                    int nrow = row + delRow[k];
                    int ncol = col + delCol[k];

                    if(nrow >= 0 && ncol >= 0 &&
                       nrow < n && ncol < n &&
                       grid[nrow][ncol] == 1)
                    {
                        int adjNode = nrow * n + ncol;

                        components.insert(ds.findUPar(adjNode));
                    }
                }

                int sizeTotal = 1;

                for(set<int>::iterator it = components.begin();
                    it != components.end();
                    it++)
                {
                    sizeTotal += ds.getSize(*it);
                }

                ans = max(ans, sizeTotal);
            }
        }

        // If grid already contains all 1's
        for(int i = 0; i < n * n; i++)
        {
            ans = max(ans, ds.getSize(i));
        }

        return ans;
    }
};