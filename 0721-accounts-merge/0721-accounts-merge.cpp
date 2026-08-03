class Disjoint {

    vector<int> parent;
    vector<int> size;

public:

    Disjoint(int n)
    {
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUparent(int node)
    {
        if(node == parent[node])
        {
            return node;
        }

        return parent[node] = findUparent(parent[node]);
    }

    void UnionBySize(int u, int v)
    {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);

        if(ulp_u == ulp_v)
        {
            return;
        }

        if(size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        Disjoint ds(n);

        unordered_map<string,int> mapMailNode;

        // Step 1 : Union accounts having common emails
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];

                if(mapMailNode.find(mail) == mapMailNode.end())
                {
                    mapMailNode[mail] = i;
                }
                else
                {
                    ds.UnionBySize(i, mapMailNode[mail]);
                }
            }
        }

        // Step 2 : Store all emails according to their ultimate parent
        vector<string> mergedMail[n];

        unordered_map<string,int>::iterator it;

        for(it = mapMailNode.begin(); it != mapMailNode.end(); it++)
        {
            string mail = it->first;

            int accountNumber = it->second;

            int parent = ds.findUparent(accountNumber);

            mergedMail[parent].push_back(mail);
        }

        // Step 3 : Prepare the answer
        vector<vector<string>> ans;

        for(int i = 0; i < n; i++)
        {
            if(mergedMail[i].size() == 0)
            {
                continue;
            }

            sort(mergedMail[i].begin(), mergedMail[i].end());

            vector<string> temp;

            // Push account holder's name
            temp.push_back(accounts[i][0]);

            // Push all merged emails
            for(int j = 0; j < mergedMail[i].size(); j++)
            {
                temp.push_back(mergedMail[i][j]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};