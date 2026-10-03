class Solution {
public:
    vector<vector<int>> ans;
    vector<int>path;
    void solve(vector<int>& candidates , int target , int index){
        int n = candidates.size();
        if(target == 0){
            ans.push_back(path);
            return;
        }
        if(target<0){
            return;
        }

        for(int i = index ; i<n ; i++){
            path.push_back(candidates[i]);
            solve(candidates,target - candidates[i],i);
            path.pop_back();  
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates,target,0);
        return ans;
    }
};