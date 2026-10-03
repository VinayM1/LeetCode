class Solution {
public:
    vector<int>path;
    vector<vector<int>>ans;
    void solve(vector<int>& nums , int index){
        int n = nums.size();
    
            ans.push_back(path);
        
        for(int i = index ; i<n ; i++){
            path.push_back(nums[i]);
            solve(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums,0);
        return ans;
    }
};