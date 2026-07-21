class Solution {
public:
    vector<vector<int>> ans;
    void solve(int index , vector<int>& candidates , int target,  vector<int>& subset){
        if(index == candidates.size()){
            return;
        }
            if(target == 0){
               ans.push_back(subset);
               return;
            }
            
        if(candidates[index]<=target){
        subset.push_back(candidates[index]);
        solve(index,candidates,target-candidates[index],subset);
        subset.pop_back();
        
        }
        solve(index+1,candidates,target,subset);



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subset;
        solve(0,candidates,target,subset);
        return ans;

    }
};