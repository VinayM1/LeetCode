class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            // If ans is empty OR no overlap
            if(ans.empty() || arr[i][0] > ans.back()[1]) {
                ans.push_back(arr[i]);
            }
            else {
                // Merge intervals
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }

        return ans;
    }
};