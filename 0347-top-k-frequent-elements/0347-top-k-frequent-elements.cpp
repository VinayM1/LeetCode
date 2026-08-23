class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        unordered_map<int,int> freq;
        vector<int> ans;
        sort(nums.begin(),nums.end());

        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }
        for(auto it : freq){
            minh.push({it.second, it.first});
            if(minh.size()>k){
                minh.pop();
            }

        }
        while(!minh.empty()){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};