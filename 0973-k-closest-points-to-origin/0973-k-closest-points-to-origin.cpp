class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,int>>maxh;
        vector<vector<int>> ans;

        for(int i = 0;i<n;i++){
                int x = points[i][0];
                int y = points[i][1];
                int dist = x*x + y*y;
                maxh.push({dist,i});
                if(maxh.size()>k){
                    maxh.pop();
                }
            
            
        }
        while(!maxh.empty()){
                ans.push_back(points[maxh.top().second]);
                maxh.pop();
            }
        return ans;

        
    }
};