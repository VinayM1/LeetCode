class Solution {
public:
    vector<vector<int>> ans;
    void solve(int index , vector<int>& candidates, int target , vector<int>& subset){
         
        if(target < 0)
            return;
        if(target == 0){
            ans.push_back(subset);
            return;
        }
        for(int i = index ; i<candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i] > target){
                break;
            }
                subset.push_back(candidates[i]);
                solve(i+1,candidates,target-candidates[i],subset);
                subset.pop_back();
        }
            
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        solve(0,candidates,target,subset);
        return ans;
        
    }
};