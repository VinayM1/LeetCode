class Solution {
public:
    vector<int>path;
    vector<vector<int>>ans;
    void solve(int n , int k , int index){
        int size = path.size();
        if(size == k){
            ans.push_back(path);
            return;
        
        }
        for(int i = index ; i<=n ; i++){
            path.push_back(i);
            solve(n,k,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        solve(n,k,1);
        return ans;
        
    }
};