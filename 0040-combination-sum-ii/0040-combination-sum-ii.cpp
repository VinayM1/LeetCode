class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    
    void solve(vector<int>& candidates , int target , int index){
        
        int n = candidates.size();
        if(target == 0){
            ans.push_back(path);
            return;
        }
        for(int i = index;i<n;i++){
            if (i > index && candidates[i] == candidates[i-1]) continue;
            if(target<candidates[i]){
                break;
            }
            path.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,0);
        return ans;
    }
};