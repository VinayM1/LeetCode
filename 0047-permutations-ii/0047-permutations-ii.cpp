class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void solve(vector<int>& nums , vector<bool>& used){
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(path.size() == n){
                ans.push_back(path);
                return;
            }
        for(int i = 0 ; i<n ; i++){

            if(i>0 && nums[i]==nums[i-1]&& !used[i-1]){
                continue;
            }
            if(used[i]){
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            solve(nums,used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        solve(nums,used);
        return ans;
    }
};