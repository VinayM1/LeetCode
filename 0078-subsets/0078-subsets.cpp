class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,vector<int>& nums, vector<int>& subset){
        if(i == nums.size()){
            ans.push_back(subset);
            return;
        }
            subset.push_back(nums[i]);
            solve(i+1,nums,subset);
            subset.pop_back();
            solve(i+1,nums,subset);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        solve(0,nums,subset);
        return ans;
    }
};