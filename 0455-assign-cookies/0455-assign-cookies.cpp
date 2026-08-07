class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        // Sort greed factors
        sort(g.begin(), g.end());

    
        sort(s.begin(), s.end());

    
        int child = 0;

        int cookie = 0;

        // Traverse both arrays
        while(child < g.size() && cookie < s.size())
        {
            
            if(s[cookie] >= g[child])
            {
                child++;
            }
            cookie++;
        }

        return child;
    }
};