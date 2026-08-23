class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        priority_queue<int,vector<int>,greater<int>>minh;
        for(int i = 0 ; i<n ; i++){
            minh.push(nums[i]);
            if(minh.size()>k){
                minh.pop();
            }
        }
        return minh.top();
    }
};